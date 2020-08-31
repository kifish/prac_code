import os
cmd_base = 'git add '
def travel(root):
    for filename in os.listdir(root):
        if os.path.isdir(os.path.join(root,filename)):
            travel(os.path.join(root,filename))
        if filename[-3:] == '.py' and os.path.isfile(filename) and filename != 'git_help.py':
            cmd = cmd_base + filename
            print(cmd)
            os.system(cmd)

root = os.path.abspath('.')
travel(root)
