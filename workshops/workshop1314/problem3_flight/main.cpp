///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Describe the “Flight” structure with flight identifier fields,
/// departure airport, destination airport and departure time
/// (structure “Time”). Write a function that takes as input
/// vector of flights and airport name displaying information
/// first about all flights arriving at the specified airport, and then
/// about all flights departing from this airport.
///
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

struct Time {
    int hour;
    int minute;
};

struct Flight {
    std::string flightIdentifier;
    std::string departureAirport;
    std::string destinationAirport;
    Time departureTime;
};

void displayFlightsAtAirport(const std::vector<Flight>& flights, const std::string& airportName) {
    std::cout << "Flights arriving at " << airportName << std::endl;
    for (const Flight& flight : flights) {
        if (flight.destinationAirport == airportName) {
            std::cout << "Flight ID: " << flight.flightIdentifier << std::endl;
            std::cout << "Departure Airport: " << flight.departureAirport << std::endl;
            std::cout << "Destination Airport: " << flight.destinationAirport << std::endl;
            std::cout << "Departure Time: " << flight.departureTime.hour << ":" << flight.departureTime.minute << std::endl;
            std::cout << std::endl;
        }
    }
    
    std::cout << "Flights departing from " << airportName << std::endl;
    for (const Flight& flight : flights) {
        if (flight.departureAirport == airportName) {
            std::cout << "Flight ID: " << flight.flightIdentifier << std::endl;
            std::cout << "Departure Airport: " << flight.departureAirport << std::endl;
            std::cout << "Destination Airport: " << flight.destinationAirport << std::endl;
            std::cout << "Departure Time: " << flight.departureTime.hour << ":" << flight.departureTime.minute << std::endl;
            std::cout << std::endl;
        }
    }
}

int main() {
    std::vector<Flight> flights = {
        {"F1", "Airport A", "Airport B", {9, 0}},
        {"F2", "Airport B", "Airport C", {10, 30}},
        {"F3", "Airport A", "Airport C", {11, 45}},
    };

    displayFlightsAtAirport(flights, "Airport A");

    return 0;
}
