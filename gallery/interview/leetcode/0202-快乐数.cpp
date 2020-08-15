//����ͨ����set ���ж�;Ҳ�����ÿ���ָ������Ȧ��

class Solution
{
public:
    int change(int n){//����Ϊ������
        int res = 0;
        while(n){
            int tmp = n % 10;
            res += tmp * tmp;
            n /= 10;
        }
        return res;
    }

    bool isHappy(int n)
    {
        int fast = n;
        int slow = n;
        do{
            slow = change(slow); //��һ��
            fast = change(fast); // ������
            fast = change(fast);
        }while(fast != slow);
        if(slow != 1) return false;
        return true;
    }
};