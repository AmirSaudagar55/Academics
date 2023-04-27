
#include<iostream>
using namespace std;

struct node
{

	char label[10];
	int ch_count;
	struct node*child[10];
	
}*root;


class book
{

	public:
		void create_tree();
		void display( node *r1);

		book()
		{
			root=NULL;
		}
};

void book::create_tree()
{

	int i,j,k, tchapters,tbooks,tsections,t_subsections;
	root = new node();
	cout<<"Enter the name of the book :";
	cin>>root->label;
	cout<<"Enter the no. of chapters in the book :";
	cin>>tchapters;
	root->ch_count=tchapters;
		for(i=0;i<tchapters;i++)
		{
			root->child[i]=new node();
			cout<<"Enter the name of chapter:";
			cin>>root->child[i]->label;		
			cout<<"Enter the no. of sections in chapter :"<<root->child[i]->label;
			cin>>tsections;
			root->child[i]->ch_count=tsections;
			for(j=0;j<tsections;j++)
			{
				root->child[i]->child[j]=new node();
				cout<<"Enter section "<<j+1<<"name";
				cin>>root->child[i]->child[j]->label;
				
				cout<<"Enter the no.subsections in section:"
				<<root->child[i]->child[j]->label;
				cin>>t_subsections;
				root->child[i]->child[j]->ch_count=t_subsections;
				
					for(k=0;k<t_subsections;
					k++)
					{
						root->child[i]->child[j]->child[k]=new node();
						cout<<"Enter subsection "<<k+1<<"name";
						cin>>root->child[i]->child[j]->child[k]->label;
					
					}		
			}
			
	
		}
}
	
	
	
void book ::display(node *r1)
{
	int i,j,k,tchapters;
	if(r1 !=NULL)
	{
		cout<<"\n---------BOOK HEIRARCHY---------";
		cout<<"\nBook title :"<<r1->label;
		tchapters=r1->ch_count;
		
		for(i=0;i<tchapters;i++)
		{
			cout<<"\nchapter :"<<i+1<<":";
			cout<<r1->child[i]->label;
			cout<<"\nsection :";
			for(j=0;j<r1->child[i]->ch_count;j++)
			{
				cout<<"\n "<<r1->child[i]->child[j]->label;
			
				for(k=0;k<r1->child[j]->ch_count;k++)
				{
					cout<<"\n"<<r1->child[i]->child[j]->child[k]->label;
				}
			}
		}
	}
	
}


int main()
{

	int choice;
	book b;
	while(1)
	{
		cout<<"\n---------------------";
		cout<<"\nBOOK TREE CREATION";
		cout<<"\n---------------------";
		cout<<"\n1.create ";
		cout<<"\n2.display ";
		cout<<"\n3.EXIT ";
		cout<<"\nEnter your choice :";
		cin>>choice;
		
		switch(choice)
		{
			case 1: b.create_tree();
			
			case 2:b.display(root);
				break;
			case 3:exit(1);
			
			default:
				cout<<"\nwrong choice!!!";	
		}
	}	
	
	

}












































