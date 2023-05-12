#pragma once
#include "patient.h"
#include "paramedic.h"
#include <memory>
#include <vector>
#include <list>

enum class AmbulanceState {IN_GARAGE, ON_ROAD, RETURNED};

class Ambulance{
    private:
        std::string registrationNumber;
        std::unique_ptr<Patient> patient;
        std::list<std::unique_ptr<Paramedic>> paramedics;
        bool isOccupied = false;
        unsigned short totalTime;
        unsigned short progressTime = 0;
        AmbulanceState state = AmbulanceState::IN_GARAGE;
        void checkRegistrationNumber(std::string registrationNumber) const;
    public:
        Ambulance(std::string registrationNumber, unsigned short totalTime);
        void operator++();
        void addParamedic(std::unique_ptr<Paramedic> paramedic);
        void startIntervention(std::unique_ptr<Patient> patient);
        void continueIntervention();
        void finishIntervention();
        bool checkPersonel() const;
        unsigned short getProgressTime() const;
        AmbulanceState getState() const;
        unsigned short getTotalTime() const;
        std::string getRegistrationNumber() const;
        bool checkOccupancy() const;
        std::unique_ptr<Patient> returnPatient();
        Patient& getPatient() const;
        Paramedic& getParamedic(std::string PESEL) const;
        void setRegistrationNumber(std::string newRegistrationNumber);
    friend std::ostream& operator<<(std::ostream& os, const Ambulance& ambulance);
};
