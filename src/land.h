//Here is Land Class
#ifndef LAND_H
#define LAND_H

class Land
{

private:

    int countField;
    int indexOfSource;
    int minPrice;

public:

    Land(){}
    Land(int count, int index)
        :countField(count), indexOfSource(index) {}
    int get_countField()    const;
    int get_indexOfSource() const;
    int get_price()         const;
    ~Land() {}

};

#endif // end of Land class
