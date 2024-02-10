#include <iostream>
class TemperatureConverter 
{
private:
	double temperature;
public:
	// Constructor to initialize temperature
	TemperatureConverter(double temp) : temperature(temp) {}
	// Setter function to set the temperature
	void setTemperature(double temp) 
{
	temperature = temp;
}
	// Getter function to get the temperature
	double getTemperature() const 
{
	return temperature;
}
	// Function to convert Fahrenheit to Celsius
	double fahrenheitToCelsius() const 
{
	return (temperature - 32.0) * 5.0 / 9.0;
}
	// Function to convert Celsius to Fahrenheit
	double celsiusToFahrenheit() const 
{
	return (temperature * 9.0 / 5.0) + 32.0;
}
};
int main() 
{
	// Get user input for temperature and choice of conversion
	double temperature;
	int choice;
	std::cout << "Enter the temperature: ";
	std::cin >> temperature;
	std::cout << "Choose conversion:\n";
	std::cout << "1. Fahrenheit to Celsius\n";
	std::cout << "2. Celsius to Fahrenheit\n";
	std::cout << "Enter your choice (1 or 2): ";
	std::cin >> choice;
	// Create an instance of TemperatureConverter
	TemperatureConverter converter(temperature);
	// Perform the chosen conversion
	switch (choice) 
{
	case 1:
	std::cout << temperature << " Fahrenheit is equal to " << converter.fahrenheitToCelsius() << " Celsius.\n";
	break;
	case 2:
	std::cout << temperature << " Celsius is equal to " << converter.celsiusToFahrenheit() << " Fahrenheit.\n";
	break;
	default:
	std::cout << "Invalid choice. Please enter 1 or 2.\n";
	return 1; // Exit program with an error code
}
	return 0;
}