
#include<string.h>

#include <iostream>

#include<string>

#include<vector>

#include<set>

#include<list>

#include<algorithm>

#include<functional>
#include<iterator>

using namespace std;
void printV(vector<int> &v){

    for(vector<int>::iterator it=v.begin();it!=v.end();it++){

        cout<<*it<<" ";

    }


}

void printList(list<int> &v){

    for(list<int>::iterator it=v.begin();it!=v.end();it++){

        cout<<*it<<" ";

    }


}





void showElem(int &n){


    cout<<n<<" ";

}

class CMyShow{

public:

    CMyShow(){

        num =0;

    }


    void operator ()(int &n){

        num++;

        cout<<n<<" ";

    }


    void printNum(){

        cout<<"num:"<<num<<endl;

    }

private:

    int num ;


};

void main41_foreaceh_transform(){

    vector<int>v1;

    v1.push_back(1);

    v1.push_back(2);

    v1.push_back(3);

    printV(v1);

    //???????? ?????????????

    for_each(v1.begin(),v1.end(),showElem);

    cout<<endl;
    //
    CMyShow mya;





    mya.printNum();

    CMyShow my1 = for_each(v1.begin(),v1.end(),mya);//??my1 ?????

    cout<<"??my1 ?????"<<endl;

    my1.printNum();//1

    cout<<"??my1???"<<endl;

    my1 = for_each(v1.begin(),v1.end(),mya);//??my1???


    my1.printNum();//2
    //1,2?????????????

    mya.printNum();
}
int increase(int i){

    return 100+i;

}
void main42_transform(){

    vector <int>v1;

    v1.push_back(1);

    v1.push_back(3);

    v1.push_back(5);

    printV(v1);

    cout<<endl;
    //?????????

    transform(v1.begin(),v1.end(),v1.begin(),increase);

    printV(v1);

    cout<<endl;
    //?????????????????

    transform(v1.begin(),v1.end(),v1.begin(),negate<int>());

    printV(v1);

    cout<<endl;

    //transform ??¡§?????????????????????

    list<int> mylist;

    mylist.resize(v1.size());


    transform(v1.begin(),v1.end(),mylist.begin(),bind2nd(multiplies<int>(),10));

    printList(mylist);

    cout<<endl;

    //transform ?????????????????

    transform(v1.begin(),v1.end(),ostream_iterator<int>(cout,"    "),negate<int>());

    cout<<endl;



}

int showElem2(int n){


    cout<<n<<" ";

    return n;


}

void main43_transform_pk_foreach(){

    vector <int>v1;

    v1.push_back(1);

    v1.push_back(3);

    v1.push_back(5);

    vector<int> v2 = v1;

    for_each(v1.begin(),v1.end(),showElem);



    transform(v2.begin(),v2.end(),v2.begin(),showElem2);//???transform ???????????????





}

void main44_adjacent_find(){


    vector <int>v1;

    v1.push_back(1);

    v1.push_back(2);

    v1.push_back(2);

    v1.push_back(2);

    v1.push_back(3);

    v1.push_back(5);

   vector<int>::iterator it =  adjacent_find(v1.begin(),v1.end());

   if(it == v1.end()){

       cout<<"?????? ??????"<<endl;

   }else{


       cout<<*it<<endl;

   }

    int index = distance(v1.begin(),it);

    cout<<"index: "<<index<<endl;


}
//??????????
void main45_binary_search(){


    vector<int> v1;

    v1.push_back(11);

    v1.push_back(10);

    v1.push_back(5);

    v1.push_back(71);

    v1.push_back(9);

   bool b = binary_search(v1.begin(),v1.end(),7);

   if(b==true){

       cout<<"?????"<<endl;

   }else{

       cout<<"????"<<endl;

   }



}

bool GreatThree(int iNum)
{
    if(iNum>3){


        return true;
    }else{

        return false;

    }





}
void main46_count_if(){

    vector<int> v1;

    v1.push_back(11);

    v1.push_back(10);

    v1.push_back(5);

    v1.push_back(7);

    v1.push_back(9);


   int num = count_if(v1.begin(),v1.end(),GreatThree);


   cout<<"num: "<<num<<endl;




}
bool Greatseven(int iNum)
{
    if(iNum>7){


        return true;
    }else{

        return false;

    }

}
void main47_find_findif(){

    vector<int> v1;

    v1.push_back(5);

    v1.push_back(10);

    v1.push_back(5);

    v1.push_back(7);

    v1.push_back(9);


 vector<int>::iterator it = find(v1.begin(),v1.end(),5);

  cout<<"*it : "<<*it<<endl;

vector<int>::iterator it2 = find_if(v1.begin(),v1.end(),Greatseven);//???????????????¡§??

    cout<<"*it2 : "<<*it2<<endl;
}

void main_merge(){
    vector<int> v1;

    v1.push_back(1);

    v1.push_back(3);

    v1.push_back(77);


    vector<int> v2;

    v2.push_back(4);

    v2.push_back(2);

    v2.push_back(6);

    vector<int> v3;

    v3.resize(v1.size()+v2.size());

    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());//v1 v2 ??????????? ????????¡ì???


    printV(v3);


}

class Student{

public:
       Student(string name,int id){

           m_name = name;

           m_id = id;
       }

public:

    void printT(){


        cout<<"m_name: "<<m_name<<"m_id: "<<m_id<<endl;


    }

public:

    string m_name;

    int m_id;


};

bool CompareS(const Student  &s1,const Student &s2){


    return(s1.m_id<s2.m_id);

}


void main_sort(){

     Student s1("yzm",12);

     Student s2("yzm1",10);

     Student s3("yzm2",11);

     Student s4("yzm3",15);

     vector<Student> v1;

     v1.push_back(s1);

     v1.push_back(s3);

     v1.push_back(s2);

     v1.push_back(s4);

     for(vector<Student>::iterator it= v1.begin();it!=v1.end();it++){

                it->printT();



     }


         cout<<endl;


        //sort ???????????????? ???????????????
       sort(v1.begin(),v1.end(),CompareS);



     for(vector<Student>::iterator it= v1.begin();it!=v1.end();it++){

                 it->printT();
     }



}


void main_random_shuffle(){


    vector<int> v1;

    v1.push_back(1);

    v1.push_back(3);

    v1.push_back(77);

    random_shuffle(v1.begin(),v1.end());

    printV(v1);


    string str = "abcdefg";



    random_shuffle(str.begin(),str.end());

    cout<<"str: "<< str<<endl;


}

 void main_reverse(){



     vector<int> v1;

     v1.push_back(1);

     v1.push_back(3);

     v1.push_back(77);

    


     string str = "abcdefg";


     reverse(str.begin(),str.end());

     cout<<"str: "<< str<<endl;





 }
int main()
{

   // main41_foreaceh_transform();

    // main42_transform();

    //main43_transform_pk_foreach();


    //main44_adjacent_find();

   //  main45_binary_search();

  //  main46_count_if();

   // main47_find_findif();


   // main_merge();


     // main_sort();

    //main_random_shuffle();

    main_reverse();




    return 0;
}

