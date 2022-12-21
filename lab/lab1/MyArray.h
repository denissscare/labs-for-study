
class MyArray{

    protected:
    double * arr_;
    int size_{};
    int capacity_{};

    public:
    MyArray();
    bool isEmpty() const{return size_ == 0;};
    int size() const {return size_;};
    int capacity() const {return capacity_;}

    void reSize();
    void addElement(const double& elem);
    void removeElement(int index);
    void printm();

    double max();
    double min();

    double& operator[](int index){return arr_[index];}

    ~MyArray(){delete[] arr_; }
}; //class end

class MyArrayExtend : public MyArray{
    public:
    virtual void sort();
    virtual void find(double x);
};
