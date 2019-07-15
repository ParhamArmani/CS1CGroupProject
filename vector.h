/******************************************
*  AUTHOR  :   Parham AghamohammadiAmghani
*  Group   :   Vector
*  CLASS   :   CS1C
*  SECTION :   MWTTH 3:00 PM - 5:20 PM
*  Due Date:   07/14/2019
*****************************************/

#ifndef VECTOR_h
#define VECTOR_h


#include <iostream>
#include <algorithm>

namespace CS1C
//All the this functionality will be within the CS1C namespace.
// Use CS1C:: to access the vector operators
{
    template <class T> // The class Vector is templated: Prior to use must define the type of the element like. vector<shape> MyVectorName(SIZE)
    class vector
    {
    private:
        
        int size_v;   // Number of the elemments inside the vector
        T *elem;      // pointer to the elements (or 0)
        int space;    // number of elements plus number of free slots
        
    public:
        //-------------------------------------------------

        vector(): size_v{0}, elem{nullptr}, space{0} {
            
            // Default constructor for the Vector
            // Pre: Recieves no parameter
            // Post: Creates the Vector Object with Zero Elements
        }
        //-------------------------------------------------

        explicit vector(int s): size_v{0}, elem{new T[s]}, space{s}
        {
            //Alternate Constructor for the Vector Class e.g: vector<double> myVectorName(NumberofElement)
            //Pre: Recieves the Size of the Element
            //Post: Constructs the object with elements
            
            for (int i = 0; i < space; ++i)
                elem[i] = T(); // elements are initialized
                }
        //-------------------------------------------------

        vector(const vector &myObject): size_v{myObject.size_v}, elem{new T[myObject.size_v]}, space{myObject.space} // copy constructo
        {
            //Copy Constructor.
            //Pre: Recieves an Object of the same type
            // Post: Constructs the object with the same size and type.
            
            std::copy(myObject.elem, myObject.elem + size_v, elem); // copy elements - std::copy() algorithm
        }
        //-------------------------------------------------

        vector(vector &&myObject): size_v{0}, elem{nullptr}, space{myObject.space}
        {
            //Move Constructor for the Vector
            //Pre: Recieve another Object
            //Post: Constructs the object.
            
            elem = myObject.elem;
            size_v = myObject.size_v;
            myObject.elem = nullptr;
            myObject.size_v = 0;
        }
        
        //-------------------------------------------------

        vector &operator=(const vector &myObject)
        {
            //Overloaded & operator
            //Pre: Requeires the Object on the LEFT = then Same Type on RHS
            
            T *p = new T[myObject.size_v];
            std::copy(myObject.elem, myObject.elem + myObject.size_v, p);
            delete[] elem;
            elem = p;
            size_v = myObject.size_v;
            return *this;   // return a self-reference
        }
        //-------------------------------------------------

        vector &operator=(vector &&myObject)
        {
            //Overloading the = Operator
            //Pre: Recieves the object.
            //Assigns the object to the new object.
            
            if(this != &myObject)
            {
                delete[] elem;
                elem = myObject.elem;
                size_v = myObject.size_v;
                myObject.elem = nullptr;
                myObject.size_v = 0;
            }
            return *this;
        }
        
        //-------------------------------------------------

        ~vector()
        {
            //Destructor for the vector class
            //Pre: N/A
            //Post: The data and the pointers will be erased.
            
            delete [] elem; // destructor
        }
        //-------------------------------------------------

        T &operator[](int n)
        {
            //Overloading the [] operator to use the defined vector like arrays.
            //Pre: Recieves an index
            //Post: Return the element with that index of any type.
            
            return elem[n]; // access: return reference
        }
        //-------------------------------------------------

        const T &operator[](int n) const
        {
            //Overloading the [] operator to use the defined vector like arrays with the difference that only used for consts.
            //Pre: Recieves an index
            //Post: Return the element with that index of any type.
            
            return elem[n];
        }
        
        //-------------------------------------------------

        int size() const
        {
            //Function to return the size of the vector.
            //Pre:
            return size_v;
        }
        
        //-------------------------------------------------

        int capacity() const
        {
            //Function that returns the value of Space
            //Pre: Recieves nothing
            //Post: Returns the Private DM of Space of the object.
            
            return space;
        }
        
        //-------------------------------------------------

        void resize(int newsize)
        {
            //This function will resize the object.
            //Pre: Recieve the New size for the vector
            //Post: Will reserve more elements and Initialize them based on their Types
            
            reserve(newsize);
            for (int i = 0; i < newsize; ++i)
            {
                elem[i] = T(); // initialize new elements
            }
            size_v = newsize;
        }
        
        //-------------------------------------------------

        void push_back(const T &obj)
        // increase vector size by one; initialize the new element with obj
        {
            //Function to push back the object to the Vector
            //Pre: Recieves an object
            //Post: Adds the object to the vector as the last element.
            
            if (space == 0)         //For the First time, it will reserve 8 elements
                reserve(8);
            else if (size_v == space) // if all spaces have filled up,
                reserve(2 * space);   // then will reserve twice the current spaces
                elem[size_v] = obj;   // assgining the object to the next index
            ++size_v;                 // Incrementing the Index
        }
        
        //-------------------------------------------------

        void reserve(int new_size)
        {
            // Function to reserve extra elements
            // Pre: Recieves the Size to be added
            // Post: Create the New object, with the new capacity and same elements from original
            
            T *p = new T[new_size];             // Create the new pointer array of the same type
            std::copy(elem, elem + size_v, p);       //Copy the same vector in the new array with new capacity.
            delete[] elem;                      //Delete the content of the previous elements
            elem = p;                           //Assigning the elements to the Originial array
        }
        
        //-------------------------------------------------

        using iterator = T *; // defining iterator to be T *
        using const_iterator = const T *; // defining iterator to be const T *
        
        //-------------------------------------------------

        iterator begin()
        {
            // Function to return the pointer to the first element
            // Pre: Recieves nnothing
            // Post: Returns the pointer of type T to the first element
            
            if (size_v == 0)        // If the vector is empty
                return nullptr;     // return a pointer 0, since no elements exist
            return &elem[0];        // Return the address of the first element
        }
        //-------------------------------------------------

        const_iterator begin() const
        {
            // Function to return the pointer to the first element
            // Pre: Recieves nnothing
            // Post: Returns the pointer of type T to the first element
            if (size_v == 0)        // If the vector is empty
                return nullptr;     // return a pointer 0, since no elements exist
            return &elem[0];        // Return the address of the first element
        }
        
        //-------------------------------------------------

        iterator end()
        {
            // Function to return the pointer to the last element
            // Pre: Recieves nnothing
            // Post: Returns the pointer of type T to the last element
            
            // If the vector is empty
            // return a pointer 0, since no elements exist
            // Return the address of the last element
            if (size_v == 0)
                return nullptr;
            return &elem[size_v];
        }
        
        //-------------------------------------------------

        
        const_iterator end() const
        {
            // Function to return the pointer to the last element
            // Pre: Recieves nnothing
            // Post: Returns the pointer of type T to the last element
            
            // If the vector is empty
            // return a pointer 0, since no elements exist
            // Return the address of the last element
            
            if (size_v == 0)
                return nullptr;
            return &elem[size_v];
        }
        
        //-------------------------------------------------

        iterator insert(iterator p, const T &myObject)
        {
            // Function to add the new pass in element just before p
            // Pre: Recieves the Interator and the const object.
            // Post: Will insert the object just before P.
            //      If the number is not in range, Will insert in the End of the Vector. Then Returns a pointer to that element in the vector.
            
            if (size_v == space){ //If completely filled up capacity,
                                  // will need to allocate more space.
                reserve(2 * space);}
            if (p > end())
            {
                std::cerr << "Invalid Position, Must be in Range" << std::endl;
                std::cerr << "Inserting the object in the end." << std::endl;
                elem[size_v] = myObject;
                ++size_v;
                return &elem[size_v];
            }
            std::copy(p, elem + size_v, p + 1);  //Copy the elements from the Target position till the end of the Vector to skip only one element to make room for the new Object.
            *p = myObject;
            ++size_v;           //Increment the Size by one.
            return p;
        }
        
        //-------------------------------------------------

        iterator erase(iterator p)
        {
            // Function to Delete one element from the vector at position P
            //Pre: Function Receives an Iterator [ A type T pointer ]
            // Post: Function Returns an Iterator.
            
            if (p == end()){ // IF both iterators are the same, Then Return itself and decrease the size_v
                return p;}
            for (iterator i = p + 1; i != end(); ++i) {// Iterator over the Elements in the Vector till the end and shit all to the Left
                *(i - 1) = *i;}
            --size_v;
            return p;
        }
        
        //-------------------------------------------------

        T low(T first, T last)
        {
            T low = first;
            for (T p=first; p!=last; ++p)
                if (*low > *p)
                    low = p;return low;
        }
        
        //-------------------------------------------------

        void selection_sort(T first, T last)
        {
            int n = last - first;
            for(int x=0; x<n; x++){
                int index_of_min = x;
                for(int y=x; y<n; y++){
                    if(*(first+index_of_min) > *(first+y)){index_of_min = y;
                    }
                }
                auto temp = *(first+x);*(first+x) = *(first+index_of_min);
                    *(first+index_of_min) = temp;
            }
            
        }
        
        
        //-------------------------------------------------
        void print_vector(){
            //Function to print the content of a vector to the console
            //Pre: The object must have been instantiated
            //     The overloaded stream operator must have been defined in a class prior to using       this class.
            //Post: The vector's elements will be printed Out to the console
            for (int i=0; i<this->size(); i++) //Will iterate through the vector's elements, as many times as the vector holds elements.
                std::cout << elem[i] << "\t"; //Outputs the elements with a "\t" gap.
                std::cout << std::endl;       // Move the output buffer to the next line once the iteration has finished.
            
        }
    };
}

#endif

