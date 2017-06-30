#include <iostream>
using namespace std;

template<typename Object>   //ģ������������ObjectΪ���Ͳ���
class  Vector
{
private:
    int theSize;                         //ʵ�����ݴ�С
    int theCapacity;                     //ʵ������������С
    Object *objects;                     //��������
public:
    enum { SPACE_CAPACITY = 16 };        //Ĭ��������С
    
    explicit Vector(int initSize = 0)    //���������캯��Ҫ��explicit()���������ں�̨ת��
        : theSize(initSize), theCapacity(initSize + SPACE_CAPACITY) {
        objects = new Object[theCapacity];
    }
    Vector(const Vector& rhs) : objects(NULL) {    //���ƹ��캯��--����operator=�����е�Vector���и���
        operator = (rhs);
    }
    ~Vector() {
        delete[] objects;
    }

    const Vector& operator = (const Vector& rhs) //���ظ�ֵ�����
    {
        if (this != &rhs)                        //���⸴������--��������
        {
            delete []objects;                    //ɾ���ɵ��ڴ�ռ�
            theSize = rhs.size();                //����ͬ����������С
            theCapacity = rhs.theCapacity;       //����ͬ����������С

            objects = new Object[capacity()];    //�����������Ƶ�Vectorͬ��������������
            for (int k = 0; k < size(); k++)
                objects[k] = rhs.objects[k]; 
        }
        return *this;
    }
    
    void resize(int newSize)
    {
        if (newSize > theCapacity)        //���ô�С
            reserve(newSize * 2 + 1);     //�´�С
        theSize = newSize;
    }

    void reserve(int newCapacity)
    {
        if (newCapacity < theSize)        //���ٺͣ�������С��һ����
            return;

        Object *oldArray = objects;       //oldArray--���ڸ��ƾ���������
        objects = new Object[newCapacity];
        for (int k = 0; k < theSize; k++)
            objects[k] = oldArray[k];

        theCapacity = newCapacity;
        delete []oldArray;
    }

    Object& operator[] (int index)
    {
        return objects[index];
    }
    const Object& operator[] (int index) const
    {
        return objects[index];
    }

    bool empty() const {
        return size() == 0;
    }
    
    int size() const {
        return theSize;
    }
    int capacity() const {
        return theCapacity;
    }
    void push_back(const Object& x) {
        if (theSize == theCapacity)
            reserve(2 * theCapacity + 1);
        objects[theSize++] = x;
    }
    
    void pop_back() {
        theSize--;
    }
    const Object& back() const {
        return objects[theSize - 1];
    }
    
    typedef Object *iterator;
    typedef const Object *const_iterator;

    iterator begin() {
        return &objects[0];
    }
    const_iterator begin() const {
        return &objects[0];
    }
    iterator end() {               //β��Ĳ����ڵ�ָ��
        return &objects[size()];     
    }
    const_iterator end() const {
        return &objects[size()];
    }
};

int main()
{
    Vector<int> test;
    int data;
    while (cin >> data)
    {
        test.push_back(data);
    }
    Vector<int>::iterator it;
    for (it = test.begin(); it != test.end(); ++it)
        cout << *it << " ";
    cout << endl;
    cout << "pop_one.....\n";
    test.pop_back();
    cout << test.back() << endl;
    return 0;
}
