#include <iostream>
#include <vector>

using namespace std;

vector<double>
input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}

void
find_minmax(vector<double> numbers, double& min, double& max,size_t& number_count) {
 min = numbers[0] ;
  max=numbers[0];

    for(int i=0; i<number_count; i++)
    {
        if (numbers[i] < min)
        {
            min = numbers[i];
        }
        if (numbers[i]> max)
        {
            max = numbers[i];
        }

    }
}

vector<size_t>
 make_histogram(double min, double max, size_t bin_count, vector<double> numbers)
 {
    vector<size_t> bins(bin_count,0);

    const double h = (max - min)/bin_count;
    for(double number : numbers)
    {
        size_t i=0;
        while (number >= min + h*(i+1))
        {
            i++;
        }
        if(i>=bin_count)
        {
            i=bin_count - 1 ;

        }
        bins[i]++;
    }
    return bins;
 }


 show_histogram_text(vector<size_t> bins,size_t bin_count){
size_t max_bins = bins[0];
    double koef;
    const int MAX_WIDTH =80-4;
    if(max_bins > MAX_WIDTH)
    {
        koef = MAX_WIDTH/ max_bins;
    }
    else
    {
        koef = 1;
    }



    for(int i=0; i<bin_count; i++)
    {
        if (bins[i]<100)
        {
            cout<<' ';
            if(bins[i]<10)
            {
                cout<<' ';
            }
            cout<<bins[i]<<"|";
            for(int j = 0; j<bins[i]*koef; j++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
    }}

int main()
{
    srand(42);
    size_t number_count;
    cerr << "Enter vector size" << endl;
    cin>> number_count;
    vector<double> numbers(number_count);
    int x;
    cerr<< "If you want to generate values enter 1, if not, enter 0"<<endl;

    cin>>x;
    if (x == 1)
    {

        for( int i = 0; i<number_count; i++)
        {
            numbers[i]= rand();
            for(i=0; i<11; i++)
            {
                numbers[i] = numbers[i] + rand();
            }
        }
    }
    if (x == 0)
    {
        cerr<<"Enter vector"<<endl;
        numbers = input_numbers(number_count);
    }
    size_t bin_count;
    cerr << "Enter number of lines" << endl;
    cin>> bin_count;

//Поиск минимума и максимума
double min, max;
find_minmax(numbers, min, max, number_count);

//расчет чисел в столбцах
vector<size_t> bins = make_histogram(min,max,bin_count,   numbers);


//отображение гистограммы
show_histogram_text(bins,bin_count);

}


/*for(size_t bin : bins){
    cout<<bin<<'|';
    for(size_t i = 0; i<bin; i++){
        cout<<'*';
    }
    cout<<endl;*/

