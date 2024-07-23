#include <iostream>
#include <vector>
#include <cmath>


//Implementing KNN algorithm

int max_element(std::vector<int> container)
{
    int minimum = -1;
    int minimum_index = 0;

    for (int i = 0; i < container.size(); i++)
    {
        if (container[i] > minimum)
        {
            minimum = container[i];
            minimum_index = i;
        }
    }
    return minimum_index;
}

int min_element(std::vector<int> container){
    int minimum=10000;
    int minimum_index=0;

    for(int i=0; i<container.size(); i++){
        if(container[i]<minimum){
            minimum=container[i];
            minimum_index=i;
        }
    }
    return minimum_index;
}

std::string predict(std::vector<std::vector<int>> array, std::vector<std::string> labels, std::vector<int> new_image, int image_size_squared)
{

    std::vector<int> differences;
    std::vector<int> result_for_current_image;
    int summation = 0;
    for(int i=0; i < array.size(); i++){
        summation=0;
        result_for_current_image.clear();

        for (int k = 0; k < image_size_squared; k++)
        {
            result_for_current_image.push_back(pow (abs(array[i][k] - new_image[k]),2));
        }

        for(int &element: result_for_current_image)
            summation+=element;


        differences.push_back(sqrt(summation));
    }


    int index = min_element(differences);


    //classification
    

    return labels[max_element(array[index])];
}

//cells with 4 pixels only, Each pixel is a range of 256 shades of grey.   1st quadrant- dog,   2nd quadrant - cat, 3rd quadrant - sheep  , and horse
