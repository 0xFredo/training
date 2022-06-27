//Module 12-1

#include <iostream>
#include <cstring>
#include "src/Queue.h"

using  namespace QueueNamespace;

int main()
{
    Queue<int> iQa(2), iQb(10); 
    try 
    { 
        iQa.put(1); 
        iQa.put(2); 
        iQa.put(3); 

        iQb.put(10); 
        iQb.put(20); 
        iQb.put(30); 

        std::cout << "Contents of integer queue iQa: "; 
        for(int i=0; i < 3; i++)
            std::cout << iQa.get() << " "; 

        std::cout << std::endl; 

        std::cout << "Contents of integer queue iQb: "; 
        for(int i=0; i < 3; i++) 
            std::cout << iQb.get() << " "; 

        std::cout << std::endl; 

        Queue<double> dQa(10), dQb(10);

        dQa.put(1.01); 
        dQa.put(2.02); 
        dQa.put(3.03); 

        dQb.put(10.01); 
        dQb.put(20.02); 
        dQb.put(30.03); 

        std::cout << "Contents of double queue dQa: "; 
        for(int i=0; i < 3; i++) 
            std::cout << dQa.get() << " "; 
        
        std::cout << std::endl; 
        
        std::cout << "Contents of double queue dQb: "; 
        for(int i=0; i < 3; i++) 
            std::cout << dQb.get() << " "; 

        std::cout << std::endl; 

    } catch(QExcept exc) { 
        std::cout << exc.msg; 
    } 

    return 0;
}