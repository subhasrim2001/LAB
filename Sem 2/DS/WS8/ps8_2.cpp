using namespace std;
class Node
{
        public:
        int data;
        Node* link;
};
void display(Node *Head)
{
    Node *temp;
    if((Head->data)==0)
    {
        cout<<"\nList empty";
    }
    else
    {
        temp=Head->link;
        while(temp!=NULL)
        {
            cout<<temp->data<<"-->";
            temp=temp->link;
        }
        cout<<"END\n";
    }
}
Node* Move_n(Node *Head, int n)//o
{
        int count=Head->data, i=2;
        Node *temp1=Head->link, *temp2=Head->link, *temp3;
        if((Head->data)==0)
        {
            return Head;
        }
        while((temp1->link->link)!=NULL)
        {
                temp1=temp1->link;
        }
        if((count-n-1)<=0)
        {
                temp2=NULL;
        }
        else
        {
                while((temp2->link)!=NULL)
                {
                        if(i==(count-n))
                        {
                                break;
                        }
                        i++;
                        temp2=temp2->link;
                }
        }
        if(temp2==NULL)
        {
                temp3=temp1->link;
                temp1->link=temp1->link->link;
                temp3->link=Head->link;
                Head->link=temp3;

        }
        else
        {
                temp3=temp1->link;
                temp1->link=temp1->link->link;
                temp3->link=temp2->link;
                temp2->link=temp3;
        }
        return Head;
}
Node* Copy(Node *Head2)//p
{
        Node *Head=NULL, *temp=Head2, *temp2;
        while(temp!=NULL)
        {
                Node *cur=new Node;
                cur->data=temp->data;
                if(Head==NULL)
                {
                        Head=cur;
                }
                else
                {
                        temp2->link=cur;
                }
                cur->link=NULL;
                temp2=cur;
                temp=temp->link;
        }
        return Head;
}
int Count(Node *Head)//n
{
        return (Head->data);
}
int Sum(Node *Head)//m
{
        int sum=0;
        Node *temp=Head->link;
        while(temp!=NULL)
        {
                sum+=temp->data;
                temp=temp->link;
        }
        return sum;
}
Node* Sort(Node *Head)//l
{
        Node *temp1=Head->link, *temp2;
        int t;
        while(temp1->link!=NULL)
        {
                temp2=temp1->link;
                while(temp2!=NULL)
                {
                        if(temp2->data < temp1->data)
                        {
                                t=temp2->data;
                                temp2->data=temp1->data;
                                temp1->data=t;
                        }
                        temp2=temp2->link;
                }
                temp1=temp1->link;
        }
        return Head;
}
Node* Delete_2(Node *Head)
{
        Node *temp=Head->link, *temp2;
        int f=0;
        while(temp->link!=NULL)
        {

                temp2=temp->link;
                temp->link=temp->link->link;
                f=1;
                delete temp2;
                Head->data=(Head->data)-1;
                temp=temp->link;
        }
        return Head;
}
Node* Insert_nth(Node *Head, int n)
{
        int count=0;
        Node *temp=Head->link, *cur=new Node;
        cout<<"\nEnter data:";
        cin>>cur->data;
        if((Head->link)==NULL)
        {
                Head->link=cur;
                cur->link=NULL;
        }
        else
        {
                while(temp->link!=NULL)
                {
                        count++;
                        if(count==n)
                        {
                                break;
                        }
                        temp=temp->link;

                }
                if(count<n)
                {
                        temp->link=cur;
                        cur->link=NULL;
                }
                else
                {
                        cur->link=temp->link;
                        temp->link=cur;
                }
        }
        Head->data=(Head->data)+1;
        return Head;
}
/*I am done till this*/
Node* Intersection(Node *Head1, Node *Head2)//i
{
        Node *temp1=Head1, *temp2=Head2, *Head3=NULL, *temp3=Head3, *cur;
        int flag=0;
        while(temp1!=NULL)
        {
                flag=0;
                temp2=Head2;
                while(temp2!=NULL)
                {
                        if((temp1->data)==(temp2->data))
                        {
                                flag=1;
                                break;
                        }
                        temp2=temp2->link;
                }
                if(flag)
                {
                        cur=new Node;
                        cur->data=temp1->data;
                        cur->link=NULL;
                        if(temp3==NULL)
                        {
                                Head3=temp3=cur;
                        }
                        else
                        {
                            temp3->link=cur;
                        }
                        temp3=cur;
                }
                temp1=temp1->link;
        }
        return Head3;
}
Node* Union(Node *Head1, Node *Head2)//h
{
        Node *Head3=NULL, *temp1, *temp2, *temp3=NULL;
        temp1=Head1;
        int flag=0;
        while(temp1!=NULL)
        {
                Node *cur=new Node;
                cur->link=NULL;
                cur->data=temp1->data;
                if(temp3==NULL)
                {
                        Head3=temp3=cur;
                }
                else
                {
                        temp3->link=cur;
                        temp3=cur;
                }
                temp1=temp1->link;
        }
        temp2=Head2;
        while(temp2!=NULL)
        {
                temp1=Head1;
                flag=0;
                while(temp1!=NULL)
                {
                        if((temp1->data)==(temp2->data))
                        {
                                flag=1;
                                break;
                        }
                        temp1=temp1->link;
                }
                if(flag==0)
                {
                        Node *cur=new Node;
                        if(temp3==NULL)
                        {
                                Head3=temp3=cur;
                        }
                        else
                        {
                                temp3->link=cur;
                                temp3=cur;
                        }
                        cur->data=temp2->data;
                        cur->link=NULL;
                }
                temp2=temp2->link;
        }

        return Head3;
}
Node* combine(Node *Head1, Node *Head2)//g
{
        Node *temp1=Head1, *temp2=Head2, *Head3=NULL, *temp3=Head3, *cur;
        while((temp1!=NULL) && (temp2!=NULL))
        {
                cur=new Node;
                cur->link=NULL;
                if(temp1->data < temp2->data)
                {
                        cur->data=temp1->data;
                        if(temp3==NULL)
                        {
                                temp3=Head3=cur;
                        }
                        else
                        {
                                temp3->link=cur;
                                temp3=cur;
                        }
                        temp1=temp1->link;
                }
                else
                {
                        cur->data=temp2->data;
                        if(temp3==NULL)
                        {
                                Head3=cur;
                        }
                        else
                        {
                                temp3->link=cur;
                        }
                        temp3=cur;
                        temp2=temp2->link;
                }
        }
        if(temp1==NULL)
        {
                while(temp2!=NULL)
                {
                        cur=new Node;
                        cur->data=temp2->data;
                        cur->link=NULL;
                        temp3->link=cur;
                        temp3=cur;
                        temp2=temp2->link;
                }
        }


        else if(temp2==NULL)
        {
                while(temp1!=NULL)
                {
                        cur=new Node;
                        cur->data=temp1->data;
                        cur->link=NULL;
                        temp3->link=cur;
                        temp3=cur;
                        temp1=temp1->link;
                }
        }
        return Head3;
}
Node* delete_n(Node *Head, int n)//f
{
        Node *temp, *temp2;
        int count;
        if(Head==NULL)
        {
                return Head;
        }
        else if(Head->link==NULL)
        {
                delete Head;
                Head=NULL;
        }
        else if(n==1)
        {
                temp=Head;
                Head=Head->link;
                delete temp;
        }
        else
        {
                count=1;
                temp=Head;
                while(temp->link->link!=NULL)
                {
                        temp=temp->link;
                        count++;
                        if(count==n-1)
                        {
                                break;
                        }

                }
                temp2=temp->link;
                temp->link=temp2->link;
                delete temp2;
        }
        return Head;
}
Node* delete_last(Node *Head)//e
{
        Node *temp, *temp2;
        if(Head==NULL)
        {
                return Head;
        }
        else if(Head->link==NULL)
        {
                delete Head;
                Head=NULL;
        }
        else
        {
                temp=Head;
                while(temp->link->link!=NULL)
                {
                        temp=temp->link;
                }
                temp2=temp->link;
                temp->link=NULL;
                delete temp2;
        }
        display(Head);
        return Head;
}
Node* reverse(Node *Head1)//d
{
        Node *temp1=Head1, *Head2=NULL;
        while(temp1!=NULL)
        {
                Node *cur=new Node;
                cur->data=temp1->data;
                cur->link=NULL;
                if(Head2==NULL)
                {
                        Head2=cur;
                }
                else
                {
                        cur->link=Head2;
                        Head2=cur;
                }
                temp1=temp1->link;
        }
        return Head2;
}
Node* free(Node *Head)//c
{
        Node *temp;
        while(Head!=NULL)
        {
                temp=Head;
                Head=Head->link;
                delete temp;
        }
        return Head;
}
Node* concat(Node *Head1, Node *Head2)//b
{
        Node *Head3, *temp1, *temp2, *temp3=NULL;
        temp1=Head1;
        while(temp1!=NULL)
        {
                Node *cur=new Node;
                cur->link=NULL;
                cur->data=temp1->data;
                if(temp3==NULL)
                {
                        Head3=temp3=cur;
                }
                else
                {
                        temp3->link=cur;
                        temp3=cur;
                }
                temp1=temp1->link;
        }
        temp1=Head2;
        while(temp1!=NULL)
        {
                Node *cur=new Node;
                cur->link=NULL;
                cur->data=temp1->data;
                if(temp3==NULL)
                {
                        Head3=temp3=cur;
                }
                else
                {
                        temp3->link=cur;
                        temp3=cur;
                }
                temp1=temp1->link;
        }
        return Head3;
}
Node* append(Node *Head) //a
{
        Node *temp, *cur= new Node;
        cout<<"\nEnter data:";
        cin>>cur->data;
        cur->link=NULL;
        if(Head==NULL)
        {
                Head=cur;
        }
        else
        {
                temp=Head;
                while(temp->link!=NULL)
                {
                        temp=temp->link;
                }
                temp->link=cur;
        }
        display(Head);
        return Head;
}

int main()
{
        Node *Head1, *Head2, *Head3;
        Head1=new Node;
        Head1->data=0;
        Head1->link=NULL;
        Head2=new Node;
        Head2->data=0;
        Head2->link=NULL;
        Head3=new Node;
        Head3->data=0;
        Head3->link=NULL;
        int ch, choice, n;
        do
        {
                cout<<"\nALGO MENU:\n";
                cout<<"\n1. Append an element\n";
                cout<<"\n2.Concatenate 2 lists\n";
                cout<<"\n3.Free all nodes in a list\n";
                cout<<"\n4.Reverse a list\n";
                cout<<"\n5.Delete the last element\n";
                cout<<"\n6.Delete the nth element\n";
                cout<<"\n7. Combine 2 ordered lists into a single ordered list\n";
                cout<<"\n8. Union of 2 lists\n";
                cout<<"\n9. Intersection of 2 lists\n";
                cout<<"\n10. Insert after nth\n";
                cout<<"\n11. Delete every second\n";
                cout<<"\n12. Place in increasing order\n";
                cout<<"\n13. Sum of Elements\n";
                cout<<"\n14. No of elements \n";
                cout<<"\n15. Move last node by n positions\n";
                cout<<"\n16. Make a second copy\n";
                cout<<"\n17. Display\n";
                cout<<"\n18. EXIT\n";
                cout<<"\nEnter your choice:";
                cin>>ch;
                switch(ch)
                {
                        case 1: {
                                        cout<<"\nEnter which list you would like to append to(1/2):";
                                        cin>>choice;
                                        if(choice==1)
                                        {
                                                Head1=append(Head1);
                                        }
                                        else if(choice==2)
                                        {
                                                Head2=append(Head2);
                                        }
                                        else
                                        {
                                                cout<<"\nInvalid choice";
                                        }
                                        break;
                                }
                        case 2: {
                                        Head3=concat(Head1, Head2);
                                        break;
                                }
                        case 3: {
                                        cout<<"\nEnter which list you would like to free(1/2):";
                                        cin>>choice;
                                        if(choice==1)
                                        {
                                                Head1=free(Head1);
                                        }
                                        else if(choice==2)
                                        {
                                                Head2=free(Head2);
                                        }
                                        else
                                        {
                                                cout<<"\nInvalid choice";
                                        }

                                        break;
                                }
                        case 4: {
                                        cout<<"\nEnter which list you would like to reverse(1/2):";
                                        cin>>choice;
                                        if(choice==1)
                                        {
                                                Head3=reverse(Head1);
                                        }
                                        else if(choice==2)
                                        {
                                                Head3=reverse(Head2);
                                        }
                                        else
                                        {
                                                cout<<"\nInvalid choice";
                                        }

                                        break;
                                }
                        case 5: {
                                        cout<<"\nEnter which list you would like to delete from(1/2):";
                                        cin>>choice;
                                        if(choice==1)
                                        {
                                                Head1=delete_last(Head1);
                                        }
                                        else if(choice==2)
                                        {
                                                Head2=delete_last(Head2);
                                        }
                                        else
                                        {
                                                cout<<"\nInvalid choice";
                                        }

                                        break;
                                }
                        case 6: {
                                        cout<<"\nEnter n:";
                                        cin>>n;
                                        cout<<"\nEnter which list you would like to delete from(1/2):";
                                        cin>>choice;
                                        if(choice==1)
                                        {
                                                Head1=delete_n(Head1, n);
                                        }
                                        else if(choice==2)
                                        {
                                                Head2=delete_n(Head2, n);
                                        }
                                        else
                                        {
                                                cout<<"\nInvalid choice";
                                        }

                                        break;
                                }
                        case 7: {
                                        Head3=combine(Head1, Head2);
                                        break;
                                }
                        case 8: {
                                        Head3=Union(Head1, Head2);
                                        break;
                                }
                        case 9: {
                                        Head3=Intersection(Head1, Head2);
                                        break;
                                }
                        case 10:{
                                        cout<<"\nEnter n:";
                                        cin>>n;
                                        cout<<"\nEnter which list you would like to insert into(1/2):";
                                        cin>>choice;
                                        if(choice==1)
                                        {
                                                Head1=Insert_nth(Head1, n);
                                        }
                                        else if(choice==2)
                                        {
                                                Head2=Insert_nth(Head2, n);
                                        }
                                        else
                                        {
                                                cout<<"\nInvalid choice";
                                        }

                                        break;
                                }
                        case 11:{
                                        cout<<"\nEnter which list you would like to delete from(1/2):";
                                        cin>>choice;
                                        if(choice==1)
                                        {
                                                Head1=Delete_2(Head1);
                                        }
                                        else if(choice==2)
                                        {
                                                Head2=Delete_2(Head2);
                                        }
                                        else
                                        {
                                                cout<<"\nInvalid choice";
                                        }
                                        break;
                                }
                        case 12:{
                                        cout<<"\nEnter which list you would like to arrange(1/2):";
                                        cin>>choice;
                                        if(choice==1)
                                        {
                                                Head1=Sort(Head1);
                                        }
                                        else if(choice==2)
                                        {
                                                Head2=Sort(Head2);
                                        }
                                        else
                                        {
                                                cout<<"\nInvalid choice";
                                        }
                                        break;
                                }
                        case 13:{
                                        cout<<"\nEnter which list you would like to find the sum of(1/2):";
                                        cin>>choice;
                                        if(choice==1)
                                        {
                                                n=Sum(Head1);
                                                cout<<"\nSum="<<n;
                                        }
                                        else if(choice==2)
                                        {
                                                n=Sum(Head2);
                                                cout<<"\nSum="<<n;
                                        }
                                        else
                                        {
                                                cout<<"\nInvalid choice";
                                        }
                                        break;
                                }
                        case 14:{
                                        cout<<"\nEnter which list you would like to find the number of nodes of(1/2):";
                                        cin>>choice;
                                        if(choice==1)
                                        {
                                                n=Count(Head1);
                                                cout<<"\nCount="<<n<<endl;
                                        }
                                        else if(choice==2)
                                        {
                                                n=Count(Head2);
                                                cout<<"\nCount="<<n<<endl;
                                        }
                                        else
                                        {
                                                cout<<"\nInvalid choice";
                                        }
                                        break;
                                }
                        case 15:{
                                        cout<<"\nEnter n:";
                                        cin>>n;
                                        cout<<"\nEnter which list you would like to move the node in(1/2):";
                                        cin>>choice;
                                        if(choice==1)
                                        {
                                                Head1=Move_n(Head1, n);
                                        }
                                        else if(choice==2)
                                        {
                                                Head2=Move_n(Head2, n);
                                        }
                                        else
                                        {
                                                cout<<"\nInvalid choice";
                                        }
                                        break;
                                }
                        case 16:{
                                        cout<<"\nEnter which list you would like to make a copy of(1/2):";
                                        cin>>choice;
                                        if(choice==1)
                                        {
                                                Head3=Copy(Head1);
                                        }
                                        else if(choice==2)
                                        {
                                                Head3=Copy(Head2);
                                        }
                                        else
                                        {
                                                cout<<"\nInvalid choice";
                                        }
                                        break;
                                }
                        case 17:{
                                        cout<<"\nEnter the list which you would like to see(1-3):";
                                        cin>>choice;
                                        if(choice==1)
                                        {
                                            display(Head1);
                                        }
                                        else if(choice==2)
                                        {
                                            display(Head2);
                                        }
                                        else if(choice==3)
                                        {
                                            display(Head3);
                                        }
                                        else
                                        {
                                            cout<<"\nInvalid input";
                                        }
                                        break;
                                }
                        case 18:{
                                        break;
                                }
                        default:{
                                        cout<<"\nInvalid Input\nPlease enter again\n";
                                }
                }
        }while(ch!=18);
}
