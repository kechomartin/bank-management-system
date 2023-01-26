#Include<Iostream>
#Include<Fstream>
#Include<Cstdlib>
Using Std::Cout;
Using Std::Cin;
Using Std::Endl;
Using Std::Fstream;
Using Std::Ofstream;
Using Std::Ifstream;
Using Std::Ios;
class Account_query{
  Private:
  Char Account_number[20];
  Char FirstName[10];
  Char LastName[10];
  Float Total_Balance;
  Public:
Void Read_data();
Void Show_data();
Void Write_rec();
Void Read_rec();
Void Search_rec();
Void Edit_rec();
Void Delete_rec();
};
Void Account_query::Read_data()
{
  Cout<<"Enter Account Number:";
  Cin>>Account_nummber;
  Cout<<"Enter First Name";
  Cin>>FirstName;
  Cout<<"Enter LastName";
  Cin>>LastName;
  Cout<<"Enter Balance";
  Cin>>Total_Balance;
  Cout<<Endl;
}
Void Account_query::Show_data()
{
 Cout< <"Account_number:"<<Account_number<<Endl;
 Cout< <"First Name:"<<FirstName<<Endl;
 Cout< <"Last Name:"<<LastName<<Endl;
 Cout< <"Current Balance:Rs ."<<Total_Balance<<Endl;
 Cout< <"-------------------------------"<<Endl;
}
Void Account_query::Write_rec()
{
  Ofstream Outline;
  Outline.Open("Record.Txt",Ios::Binary|Ios::App);
  Read_data();
  Outline.Write(Reinterpret_cast<Char*>(This),Sizeof(*This));
  Outline.Close();
}
Void Account_query::Read_rec()
{
  Ifstream Infile;
  Infile.Open("Record.Txt",Ios::Binary);
  If(!Infile)
}
Cout<<"Error In Opening! File Not Found!!"<<Endl;
Return;
{
Cout<<"N****Data From File****"<<Endl;
While(!Infile.Eof())
{
  If(Infile.Read(Reinterpret_cast<Char*>(This),Sizeof(*This))>0)
  {
    Show_data();
  }
}
Infile.Close();
}
Void Account_query::Search_rec()
{
  Int N;
  Ifstream Inflie;
  Infile.Open("Record.Txt",Ios::Binary);
  If(!Infile)
  {
    Cout< <"NError In Opening! File Not Found!!"<<Endl;
    Return;
  }
  Infile.Seekg(-,Ios::End);
  Int Count = Inflie.Tellg()/Sizeof(*This);
  Cout<<"N There Are "<<Count<<"Record In the File";
  Cout<<"N Enter Record Number To search:";
  Cin>>N;
  Infile.Seekg((N-1)*Sizeof(*This));
  Infile.Read(Reinterpret_cast<Char*>(This), Sizeof(*This));
  Show_data();
}
Void Account_query::Edit_rec()
{
  Int N;
  Fstream Iofile;
  Iofile.Open("Record.Txt",Ios::Binary);
  If(!Iofile)
  {
    Cout<<"NError In Opening!File Not Found!!"<<Endl;
    Return;
  }
  Iofile.Seekg(0, Ios::End);
  Int Cout = Iofile.Tellg()/Sizeof(*This);
  Cout<<"N There Are"<<Count<<"Record In The File";
  Cout<<"N Enter Record Number To Edit:"
  Cin>>N;
  Iofile.Seekg((N-1)*Sizeof(*This));
  Iofile.Read(Reinterpret_cast<Char*>(This),Sizeof(*This));
  Cout<<"Record"<<N<<"Has Following Data"<<Endl;
  Show_data();
  Iofile.Close();
  Ioflie.Open("Record.Txt",Ios::Out|Ios::In|Ios::Binary);
  Iofile.Seekp((N-1)*Sizeof(*This));
  Cout<<"NEnter Data To Modify"<<Endl;
  Read_data();
  Iofile.Write(Reinterpret_cast<Char*>(This),Sizeof(*This));
}
Void Account_query::Delete_rec()
{
  Int N;
  Ifstream Infile;
  Infile.Open("Record.Bank",Ios::Binary);
  If(!Infile)
  {
    Cout<<"NError In Opening! File Not Found!!"<<Endl;
    Return;
  }
  Infile.Seekg(0,Ios::End);
  Int Count = Infile.Tellg()/Sizeof(*This);
  Cout<<"N Enter Record Number To Delete:";
  Cin>>N;
  Fstream Tmpfile;
  Tmpfile.Open("Tmpfile.Txt",Ios::Out|Ios::Binary);
  Infile.Seekg(0);
  For(Int I=0; I<Count; I++)
  {
    Infile.Read(Reinterpret_cast<Char*>(This),Sizeof(*This));
    If(I==(N-1))
    Continue;
    Tpmfile.Write(Reinterpret_cast<Char*>(This),Sizeof(*This));
  }
  Infile.Close();
  Tmpfile.Close();
  Remove("Record.Bank");
  Rename("Tpmfile.Bank","Record.Bank");
}
Int Main()
{
  Account_query A;
  Int Choice;
  Cout<<"***Account Information System***"<<Endl;
  While(True)
  {
    Cout<<"Select One Option Below";
    Cout<<"Nt1-->Add Record To File";
    Cout<<"Nt2-->Show Record From File";
    Cout<<"Nt3-->Search Record From File";
    cout<<"Nt3-->Update Record";
    Cout<<"Nt4-->Delete Record";
    Cout<<"Nt5-->Quit";
    Cout<<"Nt6-->NEnter Your Choice";
    Cin<<Choice;
    Switch(Choice)
    {
      Case 1:
      A.Write_rec();
      Break;
      Case 2:
      A.Read_rec();
      Break;
      Case 3:
      A.Search_rec();
      Break;
      Case 4:
      A.Edit_rec();
      Break;
      Case 5:
      A.Delete_rec();
      Break;
      Case 6:
      Exit(0);
      Break;
      Default:
      Cout<<"NEnter Correct Choice";
      Exit(0);
    }
  }
  System("Pause");
  Return 0;
}
