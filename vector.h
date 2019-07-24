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
/**
 * @brief :CS1C namespace which will contain all the vector functionality.
 * Use :: operator to acess the members of the namespace
 * 
 */
namespace CS1C

{/**
 * @brief Templated class or nametype T.
 * 
 */
    template <class T> // 
    /**
     * @brief Class Vector.
     * \class vector
     * The class Vector is templated.
     * Prior to use must define the type of the element as follows: vector<shape> MyVectorName(SIZE)
     * 
     */
    class vector
    

    {
    private:

        int size_v;   /*< Number of the elemments inside the vector*/
        T *elem;      /*< pointer to the elements (or 0)*/
        int space;    /*< number of elements plus number of free slots*/
        
    public:
        //-------------------------------------------------
        /**
         * @brief Construct a new vector object
         * Pre: Recieves no parameter
         * Post: Creates the Vector Object with Zero Elements
         */
        vector(): size_v{0}, elem{nullptr}, space{0} {

        }
        //-------------------------------------------------
        /**
         * @brief Construct a new vector object
         * This is an alternate constructor.
         * @param s: is space available in  the vector.
         * Pre: Recieves the Size of the Element
         * Post: Constructs the object with elements
         */
        explicit vector(int s): size_v{0}, elem{new T[s]}, space{s}
        {
            for (int i = 0; i < space; ++i)
                elem[i] = T(); // elements are initialized
                }
        //-------------------------------------------------
        /**
         * @brief Construct a new vector object (CopyConstructor)
         * 
         * @param myObject:  Object of the type T.
         * Post: Constructs the object with the same size and type.
         */
        vector(const vector &myObject): size_v{myObject.size_v}, elem{new T[myObject.size_v]}, space{myObject.space} // copy constructo
        {
            std::copy(myObject.elem, myObject.elem + size_v, elem); // copy elements - std::copy() algorithm
        }
        //-------------------------------------------------
/**
 * @brief Construct a new vector object (Move Constructor)
 * 
 * @param myObject: Object of the type T.
 * Post: Constructs the object.

 */
        vector(vector &&myObject): size_v{0}, elem{nullptr}, space{myObject.space}
        {
            elem = myObject.elem;
            size_v = myObject.size_v;
            myObject.elem = nullptr;
            myObject.size_v = 0;
        }
        
        //-------------------------------------------------
        /**
         * @brief Overloaded = Operator for the Vector Class in another words: Copy assginment oPerator.
         * 
         * @param myObject: is Another object of type Vector on the LEFT HAND SIDE
         * Pre: Requeires the Object on the LEFT = then Same Type on RHS
         * @return vector& : is the
         */
        vector &operator=(const vector &myObject)
        {

            
            T *p = new T[myObject.size_v];
            std::copy(myObject.elem, myObject.elem + myObject.size_v, p);
            delete[] elem;
            elem = p;
            size_v = myObject.size_v;
            return *this;   // return a self-reference
        }
        //-------------------------------------------------
        /**
         * @brief Overloading the = Operator
         * Assigns the object to the new object.
         * @param myObject
         * @return vector& 
         */
        vector &operator=(vector &&myObject)
        {
            
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
        /**
         * @brief Destroy the vector object
         * Pre: N/A
         * Post: The data and the pointers will be erased.
         */
        ~vector()
        {
            delete [] elem; // destructor
        }
        //-------------------------------------------------

        T &operator[](int n)
        /**
         * @brief Overloading the [] operator READ AND WRITE.
         * To use the defined vector like arrays.
         * 
         * @param n: Index
         * @return T&: T& is a reference to an  Element of type T
         */
        {
            
            return elem[n]; // access: return reference
        }
        //-------------------------------------------------

        const T &operator[](int n) const
         /**
         * @brief Overloading the [] operator 
         * To use the defined vector like std arrays, READ ONLY
         * 
         * @param n: Index
         * @return T&: T& is a reference to an  Element of type T
         */
        {

            
            return elem[n];
        }
        
        //-------------------------------------------------

        int size() const
        /**
         * @brief Function to return the size of the vector.
         * @return int size_v of the vector.
         */
        {

            return size_v;
        }
        
        //-------------------------------------------------

        int capacity() const
        /**
         * @brief Function to return the capacity of the vector.
         * @return int space of the vector.
         */
        {

            
            return space;
        }
        
        //-------------------------------------------------
        /**
         * @brief This function will resize the object.
         * 
         * @param newsize: is the New size for the vector & reserves/allocates more elements and Initialize them based on their Types.
         * 
         * @return void 
         */
        void resize(int newsize)

        {            
            reserve(newsize);
            for (int i = 0; i < newsize; ++i)
            {
                elem[i] = T(); // initialize new elements
            }
            size_v = newsize;
        }
        
        //-------------------------------------------------
        /**
         * @brief Function to push back the object into the Vector.
         * Increase vector size by one; initialize the new element with obj
         * 
         * @param obj: is the Object of type T& to be inputted into the vector.
         * Post: Adds the object to the vector as the last element.
         */
        void push_back(const T &obj)
        {
            
            if (space == 0)         //For the First time, it will reserve 8 elements
                reserve(8);
            else if (size_v == space) // if all spaces have filled up,
                reserve(2 * space);   // then will reserve twice the current spaces
                elem[size_v] = obj;   // assgining the object to the next index
            ++size_v;                 // Incrementing the Index
        }
        
        //-------------------------------------------------
        /**
         * @brief Function to reserve extra elements
         * @param new_size: the Size to be added
         * Post: Create the New object, with the new capacity and same elements from original
         */
        void reserve(int new_size)
        {
            T *p = new T[new_size];             // Create the new pointer array of the same type
            std::copy(elem, elem + size_v, p);       //Copy the same vector in the new array with new capacity.
            delete[] elem;                      //Delete the content of the previous elements
            elem = p;                           //Assigning the elements to the Originial array
            space = new_size;

        }
        
        //-------------------------------------------------

        using iterator = T *; // defining iterator to be T *
        using const_iterator = const T *; // defining iterator to be const T *
        
        //-------------------------------------------------

        /**
         * @brief Function to return the pointer to the first element READ & WRITE 
         * Pre: Recieves nnothing
         * @return iterator: iterator is a pointer of type T*
         */
        iterator begin()
        {
            if (size_v == 0)        // If the vector is empty
                return nullptr;     // return a pointer 0, since no elements exist
            return &elem[0];        // Return the address of the first element
        }
        //-------------------------------------------------
        /**
         * @brief Function to return the pointer to the first element READ ONLY 
         * Pre: Recieves nnothing
         * @return iterator: iterator is a pointer of type T*
         */
        const_iterator begin() const
        {
            if (size_v == 0)        // If the vector is empty
                return nullptr;     // return a pointer 0, since no elements exist
            return &elem[0];        // Return the address of the first element
        }
        
        //-------------------------------------------------
        /**
         * @brief Function to return the pointer to the last element READ & WRITE
         * If the vector is empty.
         * Returns a pointer 0, since no elements exist. Otherwise returns the address of the last element
         * @return const_iterator: the pointer of type T to the last element or 0 if no elements exist in the container.
         */
        iterator end()
        {

            if (size_v == 0)
                return nullptr;
            return &elem[size_v];
        }
        
        //-------------------------------------------------
        /**
         * @brief Function to return the pointer to the last element READ ONLY
         * 
         * @return const_iterator: the pointer of type T to the last element or 0 if no elements exist in the container.
         */
        
        const_iterator end() const
        {
            if (size_v == 0)
                return nullptr;
            return &elem[size_v];
        }
        
        //-------------------------------------------------
        /**
         * @brief Function to add the new pass in element just before p
         * 
         * @param p: is an  Interator of type T * .
         * @param myObject: is the constant object of type T& .
         * This function will insert the object just before P. If the number is not in range, Will insert in the End of the Vector. Then Returns a pointer to that element in the vector.
         * @return iterator.
         * returns the iterator of type T*
         */
        iterator insert(iterator p, const T &myObject)
        {

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
        /**
         * @brief Function to Delete one element from the vector at position P
         * 
         * @param p 
         * p is an iterator of T*
         * @return iterator 
         * returned value will be of type iterator of T *
         */
        iterator erase(iterator p)
        {

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
        /**
         * @brief Selection Sort algorithm for Vector Container
         * 
         * @param first
         * first is the index of the element within the vector.
         * @param last 
         * last is the index of the last element within the vector.
         */
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
        /**
         * @brief Function to print the content of a vector to the console
         * Pre: The object must have been instantiated
         * The overloaded stream operator must have been defined in a class prior to using  this class.
         * Post: The vector's elements will be printed Out to the console
         */
        void print_vector(){
            for (int i=0; i<this->size(); i++) //Will iterate through the vector's elements, as many times as the vector holds elements.
                std::cout << elem[i] << "\t"; //Outputs the elements with a "\t" gap.
                std::cout << std::endl;       // Move the output buffer to the next line once the iteration has finished.
            
        }
    };
}

#endif

