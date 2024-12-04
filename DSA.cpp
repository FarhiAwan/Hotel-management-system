#include<iostream>
using namespace std;
class Hotel
{
	private:
		struct Node
		{
			int id, date;
			string name,roomtype;
			Node*next;
		};
		public:
	    Node*head=NULL;
		void insert();
		void menu();
		void update();
		void search();
		void del();
		void sort();
		void show();
		void list();
		
			
};
void Hotel::menu()
{
	p:
	int choice;
	cout<<"\n";
	cout<<"\tWelcome to Hotel Management System\n"<<endl;
	cout<<"\n\t_________Hotel Management System________";
	cout<<"\n\nS.No  Function            Description"<<endl;
	cout << "\n1\tAllocate Room\t\t\tInsert New Room";
    cout << "\n2\tSearch Room\t\t\tSearch Room with RoomID";
    cout << "\n3\tUpdate Room\t\t\tUpdate Room Record";
    cout << "\n4\tDelete Room\t\t\tDelete Room with RoomID";
    cout << "\n5\tShow Room Records\t\tShow Room Records that (we Added)";
    cout << "\n6\tExit" << endl;

    cout << "Enter Your Choice" << endl;
    cin>>choice;
    switch(choice)
    {
    	case 1:
    	    insert();
    	 menu();
    	case 2:
    		search();
    		menu();
    		case 3:
    			update();
    		menu();	
    	case 4:
		  del();
		  menu();
		  case 5:
		  	sort();
		  	show();
		  	menu();
		  	case 6:
		  		exit(0);
		  		default:
		  			cout<<"Invalid Choice";
					
	}
	
}
void Hotel::insert(){
	cout<<"\n\t_________ Hotel Management Sysytem________";
	Node*new_node=new Node;
	cout<<"\nEnter Room ID"<<endl;
	cin>>new_node->id;
	cout<<"\nEnter Customer Name"<<endl;
	cin>>new_node->name;
	cout<<"\nEnter Allocated Date"<<endl;
	cin>>new_node->date;
	cout<<"\nEnter Room Type(single/double)"<<endl;
	cin>>new_node->roomtype;
	
	if(head==NULL){
		head=new_node;
	}
	else{
		Node*ptr=head;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=new_node;
	}
	cout<<"\n\n\t\t New Room Inserted";
}
void Hotel::search(){
	cout<<"\n\t_________ Hotel Management Sysytem________";
	int t_id;
	if(head==NULL){
		cout<<"\n\nLinked list is Empty";
	}
	else{
		cout<<"\n\nRoom Id";
		cin>>t_id;
		Node*ptr=head;
		while(ptr!=NULL){
			if(t_id==ptr->id){
				cout<<"\n\nRoom ID"<<ptr->id;
				cout<<"\n\nCustomer NAme"<<ptr->name;
				cout<<"\n\nAllocated Date"<<ptr->date;
				cout<<"\n\nRoom Type"<<ptr->roomtype;
			}
			ptr=ptr->next;
		}
	
	}
}
void Hotel::update(){
	cout<<"\n\t_________ Hotel Management Sysytem________";
	int t_id;
	if(head==NULL){
		cout<<"\n\nLinked list is Empty";
	}
	else{
		cout<<"\n\nRoom ID";
		cin>>t_id;
		Node*ptr=head;
		while(ptr!=NULL){
		   if(t_id==ptr->id){
		    cout<<"\nEnter Room ID"<<endl;
	        cin>>ptr->id;
	        cout<<"\nEnter Customer Name"<<endl;
	        cin>>ptr->name;
	        cout<<"\nEnter Allocated Date"<<endl;
	        cin>>ptr->date;
	        cout<<"\nEnter Room Type(single/double)"<<endl;
	        cin>>ptr->roomtype;
	        cout<<"\n\n\t\t Upadte Record Successfully";
		   }
		   	ptr=ptr->next;
		   
		}
}	
}
void Hotel::del(){
	cout<<"\n\t_________ Hotel Management Sysytem________";
	int t_id;
	if(head==NULL){
		cout<<"\n\nLinked list is Empty";
	}
	else{
		cout<<"\n\nRoom ID";
		cin>>t_id;
		if (t_id=head->id){
			Node*ptr=head;
			head=head->next;
			delete ptr;
			cout<<"Deleted Room Record Sucessfully\n";
			
		}
		else{
		 Node*pre=head;
		 Node*ptr=head;
		 while(ptr!=NULL){
		 	if(t_id==ptr->id){
		 		pre->next=ptr->next;
		 		delete ptr;
		 		cout<<"Deleted Room Record Sucessfully\n";
		 		break;
		 		
			 }
			 pre=ptr;
			 ptr=ptr->next;
		 }
			
	}
}
void Hotel::show (){
	 Node*ptr=head;
	 while(ptr!=NULL){
	 	
	 	cout<<"\n\nRoom ID"<<ptr->id;
	 	
		cout<<"\n\nCustomer NAme"<<ptr->name;
		
		cout<<"\n\nAllocated Date"<<ptr->date;
		
		cout<<"\n\nRoom Type"<<ptr->roomtype;
	 	ptr=ptr->next;
	 }
}	
void Hotel::sort(){
	if(head==NULL){
		cout<<"\n\nLinked list is Empty";
		menu();
	}
	int count=0,t_date,t_id;
	string t_name,t_roomtype;
	Node*ptr=head;
	while(ptr!=NULL){
		count++;
		ptr=ptr->next;
	}
	for(int i=1;i<=count;i++){
		Node*ptr=head;
		for(int j=1;j<count;j++){
			if(ptr->id>ptr->next->id){
				t_id=ptr->id;
				t_name=ptr->name;
				t_date=ptr->date;
				t_roomtype=ptr->roomtype;
				//Save data into Current Node
				ptr->id=ptr->next->id;
				ptr->name=ptr->next->name;
				ptr->date=ptr->next->date;
				ptr->roomtype=ptr->next->roomtype;
				//save data into next Node
				ptr->next->id=t_id;
				ptr->next->name=t_name;
				ptr->next->date=t_date;
				ptr->next->roomtype=t_roomtype;
			}
			ptr=ptr->next;
	}
}
}
int main()
{
	Hotel h;
	h.menu();
}

