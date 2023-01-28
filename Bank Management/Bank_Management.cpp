#include <bits/stdc++.h>

using namespace std;

class BankAccount {
    public:
        string name, address;
        int age,acocuntNumber;
    private:
        string password;
    protected:
        int balance;
    public:
        BankAccount(string name,string address, int age, string password){
            this->name=name;
            this->address=address;
            this->age=age;
            this->balance=0;
            this->password = password;
            this->acocuntNumber = rand()%1000000000;
        }
        
        void setPassword(string bPassword,string sPasswoprd){
            if(this->password == bPassword){
                this->password = sPasswoprd;
                cout<<"Your password changed Successfully"<<endl;
            }
            else{
                cout<<"Sorry wrong password"<<endl;
            }
        }

        void addMoney(int amount){
            this->balance += amount;
        }

        void withdrawMoney(string password, int amount){
            if(this->password == password && amount<this->balance){
                this->balance -= amount;
                cout<<"After withdraw your Balance: "<<this->balance<<endl;
            }
            else if(this->password != password){
                cout<<"Pasword mismatch"<<endl;
            }
            else{
                cout<<"Insuficient Funds"<<endl;
            }
        }

        void viewPassword (){
            cout<<"Your current password is: "<<this->password<<endl;
        }
    friend class MyCash;
};

class MyCash{
    protected:
        int mbalance;
    public:
        MyCash(){
            this->mbalance = 0;
        }
        void addMoneyFromAccount(BankAccount *myAccount,string password,int amount){
            if(myAccount->balance > amount && myAccount->password == password){
                myAccount->balance -= amount;
                this->mbalance += amount;
                cout<<"Current Bank Balance: "<<myAccount->balance<<endl;
                cout<<"Current My Cash Balance: "<<this->mbalance<<endl;
            }
            else if(myAccount->password !=password) cout<<"Password Mismatch"<<endl;
            else{
                cout<<"Insuficient Funds"<<endl;
            }
        }

};

BankAccount *createAccount (){
    cout<<"CREATE ACCOUNT"<<endl;
    string name, address, password;
    int age;
    cin>>name>>address>>age>>password;
    BankAccount *myAccount = new BankAccount(name,address,age,password);
    return myAccount;
}

void addMoney(BankAccount *myAccount){
    cout<<"ADD MONEY"<<endl;
    cout<<"Enter amount  to add Money"<<endl;
    int amount;
    cin>>amount;
    myAccount->addMoney(amount);
}

void withdrawMonry(BankAccount *myAcount){
    cout<<"CASH OUT"<<endl;
    string password;
    int amount;
    cout<<"Enter your password"<<endl;
    cin>>password;
    cout<<"Enter amount to withdraw"<<endl;
    cin>>amount;
    myAcount->withdrawMoney(password,amount);
}

void changePassword(BankAccount *myAccount){
    cout<<"Reset Password"<<endl;
    cout<<"First enter your current pass and then enter the pass you want to set"<<endl;
    string bPass, sPass;
    cin>>bPass>>sPass;
    myAccount->setPassword(bPass,sPass);
}

void addMcashFromAccount(BankAccount *myAccount, MyCash *myCash){
    cout<<"Add money to MyCash From Bank"<<endl;
    string password;
    int amount;
    cout<<"Enter Your Password and amount"<<endl;
    cin>>password>>amount;
    myCash->addMoneyFromAccount(myAccount,password,amount);

}
int main(){
    BankAccount *account = createAccount();
    MyCash *myCash = new MyCash();
    Flag:
        cout<<"1. Add money to bank account"<<endl;
        cout<<"2. Withdraw Money from account"<<endl;
        cout<<"3. Add Money to MyCash from Bank account"<<endl;
        cout<<"4. Change Password"<<endl;
        cout<<"5. Close"<<endl;
        int option;
        cin>>option;
        if(option == 1){
            addMoney(account);
            goto Flag;
        }
        else if(option == 2){
            withdrawMonry(account);
            goto Flag;
        }
        else if(option == 3){
            addMcashFromAccount(account,myCash);
            goto Flag;
        }
        else if(option == 4){
            changePassword(account);
            goto Flag;
        }
        else if(option == 5){
            cout<<"Thanks for using our banking system"<<endl;
        }
        else{
            cout<<"Please Enter a valid option"<<endl<<endl;
            goto Flag;
        }
    return 0;
}