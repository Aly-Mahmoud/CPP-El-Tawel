class Dog
{

    private:
        string name;
        int age;

    public:

        Dog() : Dog("NULL",0) {std::cout <<"defult constructor has been called"<<std::endl;} 

        Dog(string source_1 , int omr ) 
        {
            name = source_1;
            age = omr;
            std::cout <<"parametrized constructor has been called"<<std::endl;
        }

        void set_name (string n) {name = n;}
        string get_name() {return name;}

        void set_age(int a) {age = a;}
        int get_age() {return age;}
        int get_dog_years(){return age*7;}

        string speak () {return "Woof";}

        ~Dog(){std::cout<<"Destructor has been called"<<std::endl;}
};