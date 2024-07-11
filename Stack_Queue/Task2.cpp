#include "ArrayBasedStack.cpp"
#include "LinkedBasedStack.cpp"
#include "ArrayBasedQueue.cpp"
#include "LinkedBasedQueue.cpp"

int main()
{
    ifstream input("task2_input.txt");
    ofstream output("task2_output.txt");

    int n,c;
    input>>n>>c;
    MyLinkedQueue<int> que,qind;
    MyLinkedStack<int> stck,sind;
    int person[n+1];
    int arrival[n+1];
    int stck_last=0;
    int serving_person=-2;
    int serving_time=-2;
    for(int count=1;count<=n;count++)
    {
        int s,d;
        input>>s>>d;
        if(que.length() && s>=que.frontValue())
        {
            person[qind.dequeue()]=que.dequeue();
        }
        if(s>=serving_time)
        {
            if(serving_person!=-2)
                person[serving_person]=serving_time;
            //output<<serving_person<<" "<<serving_time<<" "<<stck.length()<<endl;

            if(stck.length()>0)
            {
                //output<<"herre"<<endl;
                serving_person=sind.pop();
                serving_time+=stck.pop();
                person[serving_person]=serving_time;
            }
            else{
                serving_person=-2;
                serving_time=-2;
            }
        }
        if(que.length()>3)
        {
            if(serving_person<0)
            {
                serving_person=count;
                serving_time=s+d;
                if(stck.length()==0) person[serving_person]=serving_time;
            }
            else{
                stck.push(d);
                sind.push(count);
                arrival[count]=s;
                //output<<stck.length()<<endl;
            }   
        }
        else{
            if(count==1)
            {
                que.enqueue(s+d);
                qind.enqueue(count);
            } 
            else{
                que.enqueue(que.rearValue()>s?que.rearValue()+d:s+d);
                qind.enqueue(count);
            }
        }
        // que.print(output,-2);
        // qind.print(output,-2);
        // stck.print(output,-2);
        // sind.print(output,-2);
    }
    while(stck.length()!=0)
    {
        serving_person=sind.pop();
        if(serving_time>0) serving_time+=stck.pop();
        else serving_time=stck.pop();
        person[serving_person]=serving_time;
    }
    while(que.length()!=0)
    {
        person[qind.dequeue()]=que.dequeue();
    }
    for(int i=1;i<=n;i++)
    {
        output<<i<<" > ";
        if(person[i]<=c) output<<person[i]<<endl;
        else output<<c<<endl;
    }
}