#include <iostream>
#include <random>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// Generar un vector con una cantidad de puntos aleatorios con una dimensión
vector<vector<float>> generateRandomPoints(int numPoints, int dimension) {
 
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<> dis(0.0, 1.0);
  
  vector<vector<float>> points(numPoints);
  
  for (int i = 0; i < numPoints; i++)
  {
    for (int j = 0; j < dimension; j++)
    {
      points[i].push_back(float(dis(gen)));
    }
  }

  return points;
}

// Generar un vector de las distancias entre los pares de puntos dado un vector de puntos
// La distancia se calcula usando la formula de distancia euclidiana
vector<float> generateDistances(vector<vector<float>> points) {

  vector<float> distances;
  
  for (int i = 0; i < points.size(); i++)
  {
    for (int j = i + 1; j < points.size(); j++)
    {
      float distance = 0.0;
      for (int k = 0; k < points[i].size(); k++)
      {
        distance += pow(points[i][k] - points[j][k], 2);
      }
      distance = sqrt(distance);
      distances.push_back(distance);
    }
  }

  return distances;
}

// Escribir las distancias en un documento CSV para su tratamiento
void writeDistancesToCSV(vector<int> dimensions, vector<vector<vector<float>>>& allDistances) {
  ofstream file("distances.csv");
  if (!file.is_open())
  {
    return;
  }

  for (int dim : dimensions) {
    file << dim << ",";
  }
  file << endl;

  for (size_t i = 0; i < allDistances[0][0].size(); ++i)
  {
    for (size_t j = 0; j < allDistances.size(); ++j)
    {
        file << allDistances[j][0][i] << ",";
    }
    file << endl;
  }

  file.close();
}

//Programa principal
int main() {
  int numPoints = 100;
  vector<int> dimensions = {10, 50, 100, 500, 1000, 2000, 5000};
  vector<vector<vector<float>>> allDistances(dimensions.size());

  for (size_t i = 0; i < dimensions.size(); ++i) {
    vector<vector<float>> points = generateRandomPoints(numPoints, dimensions[i]);
    vector<float> distances = generateDistances(points);
    allDistances[i].push_back(distances);
    points.clear();
  }

  writeDistancesToCSV(dimensions, allDistances);

  return 0;
}