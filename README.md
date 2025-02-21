student.h (Header file)

    Define Student class
    Private: firstName, lastName, credits, address, birthDate, gradDate
    Public: Student(), Student(string), ~Student(), init(string), printStudent(), getLastFirst()

student.cpp (Implementation)

    Student()  Initialize pointers, set default values
    Student(string)  Call init()
    ~Student()  Delete dynamically allocated memory
    init(string)  Parse student info, set values
    printStudent()  Print student details

address.h

    Define Address class
    Private: street, town, state, zipCode
    Public: Address(), init(string, string, string, string), printAddress()

address.cpp

    Address()  Default values
    init(string, string, string, string)  Assign values
    printAddress() → Print address

date.h

    Define Date class
    Private: day, month, year
    Public: Date(), init(string), printDate()

date.cpp

    Date()  Default values
    init(string)  Parse date from string
    printDate()  Print formatted date

test.cpp

    Create Student object
    Call printStudent() to verify output
