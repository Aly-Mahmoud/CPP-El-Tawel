#include <iostream>

// Abstract base class
class AbstractDevice 
{
    public:
        virtual void start() = 0; // Pure virtual function
        virtual void stop() = 0;  // Pure virtual function
};

class Printer : public AbstractDevice 
{
    // public:
    private:
        void start() override 
        {
            std::cout << "Printer starting..." << std::endl;
        }

        void stop() override 
        {
            std::cout << "Printer stopping..." << std::endl;
        }
};

class Scanner : public AbstractDevice 
{
    // public:
    private:
        void start() override 
        {
            std::cout << "Scanner starting..." << std::endl;
        }

        void stop() override 
        {
            std::cout << "Scanner stopping..." << std::endl;
        }
};

void operateDevice(AbstractDevice& device) 
{
    device.start();
    // Perform operations...
    device.stop();
}

int main() 
{
    Printer printer;
    Scanner scanner;

     operateDevice(printer); // Outputs: Printer starting... Printer stopping...
     operateDevice(scanner); // Outputs: Scanner starting... Scanner stopping...

     return 0;
}