#pragma once
#include "serviceDataBase.h"
#include "reception.h"
#include "ambulanceDispatch.h"
#include "ward.h"

#include <string>
#include <list>
#include <memory>


class Hospital{
    private:
        std::string name;
        std::list<std::unique_ptr<Ward>> wardsList;
        std::list<std::unique_ptr<Doctor>> doctorsList;
        std::list<std::unique_ptr<Nurse>> nursesList;
        // std::unique_ptr<ServiceDataBase> serviceDataBase;
        std::unique_ptr<Reception> reception;
        std::unique_ptr<AmbulanceDispatch> ambulanceDispatch;
    public:
        Hospital(std::string name, std::list<std::unique_ptr<Ward>> wardsList,
                std::list<std::unique_ptr<Doctor>> doctorsList,
                std::list<std::unique_ptr<Nurse>> nursesList,
                std::unique_ptr<Reception> reception,
                std::unique_ptr<AmbulanceDispatch> ambulanceDispatch);
        bool checkIfPlacesIDUnique() const;
        void addDoctor(std::unique_ptr<Doctor> doctor);
        void addNurse(std::unique_ptr<Nurse> nurse);
        void removeDoctor(std::unique_ptr<Doctor> doctor);
        void removeNurse(std::unique_ptr<Nurse> nurse);

        std::unique_ptr<Doctor> moveDoctor(std::unique_ptr<Doctor> doctor);
        std::unique_ptr<Nurse> moveNurse(std::unique_ptr<Nurse> nurse);

        std::list<std::unique_ptr<Ward>>& getWardsList();
        std::list<std::unique_ptr<Doctor>>& getDoctorsList();
        std::list<std::unique_ptr<Nurse>>& getNursesList();
        std::unique_ptr<Reception>& getReception();
        std::unique_ptr<AmbulanceDispatch>& getAmbulanceDispatch();
        // std::unique_ptr<ServiceDataBase>& getServiceDataBase();
        std::string getName() const;
};
