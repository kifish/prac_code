#!/usr/bin/env python
# -*- coding: utf-8 -*-
#---author:SErHo-----
#---url: https://gist.github.com/2773445

from PyQt4 import QtCore, QtGui
from time import sleep


class RockPI(QtGui.QWidget):

    def __init__(self, parent=None):
        super(RockPI, self).__init__(parent)

        self.resize(480, 320)

        spinLabel = QtGui.QLabel(u"位数: ")
        self.spinBox = QtGui.QSpinBox()
        self.spinBox.setMaximum(100000)

        resultLabel = QtGui.QLabel(u"结果: ")
        self.resultText = QtGui.QTextEdit()
        self.resultText.setReadOnly(True)

        self.startButton = QtGui.QPushButton(u"开始")
        self.resetButton = QtGui.QPushButton(u"重置")

        buttonLayout2 = QtGui.QHBoxLayout()
        buttonLayout2.addWidget(self.startButton)
        buttonLayout2.addWidget(self.resetButton)

        mainLayout = QtGui.QGridLayout()
        mainLayout.addWidget(spinLabel, 0, 0)
        mainLayout.addWidget(self.spinBox, 0, 1)
        mainLayout.addWidget(resultLabel, 1, 0, QtCore.Qt.AlignTop)
        mainLayout.addWidget(self.resultText, 1, 1)
        mainLayout.addLayout(buttonLayout2, 3, 1)

        self.setLayout(mainLayout)
        self.setWindowTitle("Rock PI")
        #self.setWindowIcon(QtGui.QIcon('pi.png')) Icon for Windows

        self.timer = None
        self.connect(self.startButton, QtCore.SIGNAL("clicked()"), self.start)
        self.connect(self.resetButton, QtCore.SIGNAL("clicked()"), self.reset)

    def updateResult(self, value):
        newValue = self.resultText.toPlainText() + value
        self.resultText.setText(newValue)
        if len(newValue) == (self.spinBox.value() + 1):
            self.startButton.setText(u"开始")
            self.startButton.setEnabled(False)

    def reset(self):
        if self.timer:
            self.disconnect(self.timer, QtCore.SIGNAL("updateresult"),
                            self.updateResult)
            self.timer.stop()
            self.timer.quit()
            self.timer.wait()
            self.timer.deleteLater()

        self.timer = None
        self.resultText.clear()
        self.spinBox.setValue(0)
        self.startButton.setText(u"开始")
        self.startButton.setEnabled(True)
        self.disconnect(self.startButton, QtCore.SIGNAL("clicked()"),
                        self.suspend)
        self.connect(self.startButton, QtCore.SIGNAL("clicked()"),
                     self.start)

    def start(self):
        self.times = self.spinBox.value()
        if not self.times:
            return
        if not self.timer:
            self.timer = Timer(self.times)
            self.connect(self.timer, QtCore.SIGNAL("updateresult"),
                         self.updateResult)

        self.timer.start()
        self.startButton.setText(u"暂停")
        self.disconnect(self.startButton, QtCore.SIGNAL("clicked()"),
                        self.start)
        self.connect(self.startButton, QtCore.SIGNAL("clicked()"),
                     self.suspend)

    def suspend(self):
        self.timer.stop()
        self.startButton.setText(u"开始")
        self.disconnect(self.startButton, QtCore.SIGNAL("clicked()"),
                        self.suspend)
        self.connect(self.startButton, QtCore.SIGNAL("clicked()"),
                     self.start)


class Timer(QtCore.QThread):

    def __init__(self, times, parent=None):
        super(Timer, self).__init__(parent)
        self.stoped = False
        self.mutex = QtCore.QMutex()  # Locker
        self.pi = pi_digits()
        self.times = times
        self.printed = False
        self.count = 0

    def run(self):
        with QtCore.QMutexLocker(self.mutex):
            self.stoped = False
        while True:
            if self.stoped or (self.count == self.times):
                return
            value = self.pi.next()
            if not self.printed:
                value = str(value) + "."
                self.printed = True
            self.emit(QtCore.SIGNAL("updateresult"), str(value))
            self.count += 1
            sleep(0.1)

    def stop(self):
        with QtCore.QMutexLocker(self.mutex):
            self.stoped = True


def pi_digits():
    """generator for digits of pi"""
    q, r, t, k, n, l = 1, 0, 1, 1, 3, 3
    while True:
        if 4*q+r-t < n*t:
            yield n
            q, r, t, k, n, l = (10*q, 10*(r-n*t), t, k, (10*(3*q+r))/t-10*n, l)
        else:
            q, r, t, k, n, l = (q*k, (2*q+r)*l, t*l, k+1,
                                (q*(7*k+2)+r*l)/(t*l), l+2)


if __name__ == '__main__':
    import sys
    app = QtGui.QApplication(sys.argv)

    rockpi = RockPI()
    rockpi.show()
    sys.exit(app.exec_())
