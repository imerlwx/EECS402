#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "IntersectionSimulationClass.h"
#include "random.h"

//Programmer: Wengxi Li
//Date: April 2022
//Purpose: A class that will act as the basis for an event-driven
//         simulation involving traffic flow through an intersection
//         that is managed via a traffic light.

void IntersectionSimulationClass::readParametersFromFile(
     const string &paramFname
     )
{
  bool success = true;
  ifstream paramF;

  paramF.open(paramFname.c_str());

  //Check that the file was able to be opened...
  if (paramF.fail())
  {
    success = false;
    cout << "ERROR: Unable to open parameter file: " << paramFname << endl;
  }
  else
  {
    //Now read in all the params, according to the specified format of
    //the text-based parameter file.
    if (success)
    {
      paramF >> randomSeedVal;
      if (paramF.fail() ||
          randomSeedVal < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set random generatsor seed" << endl;
      }
    }

    if (success)
    {
      paramF >> timeToStopSim;
      if (paramF.fail() ||
          timeToStopSim <= 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set simulation end time" << endl;
      }
    }

    if (success)
    {
      paramF >> eastWestGreenTime >> eastWestYellowTime;
      if (paramF.fail() ||
          eastWestGreenTime <= 0 ||
          eastWestYellowTime <= 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set east-west times" << endl;
      }
    }

    if (success)
    {
      paramF >> northSouthGreenTime >> northSouthYellowTime;
      if (paramF.fail() ||
          northSouthGreenTime <= 0 ||
          northSouthYellowTime <= 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set north-south times" << endl;
      }
    }

    if (success)
    {
      paramF >> eastArrivalMean >> eastArrivalStdDev;
      if (paramF.fail() ||
          eastArrivalMean <= 0 ||
          eastArrivalStdDev < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set east arrival distribution" << endl;
      }
    }

    if (success)
    {
      paramF >> westArrivalMean >> westArrivalStdDev;
      if (paramF.fail() ||
          westArrivalMean <= 0 ||
          westArrivalStdDev < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set west arrival distribution" << endl;
      }
    }

    if (success)
    {
      paramF >> northArrivalMean >> northArrivalStdDev;
      if (paramF.fail() ||
          northArrivalMean <= 0 ||
          northArrivalStdDev < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set north arrival distribution" << endl;
      }
    }

    if (success)
    {
      paramF >> southArrivalMean >> southArrivalStdDev;
      if (paramF.fail() ||
          southArrivalMean <= 0 ||
          southArrivalStdDev < 0)
      {
        success = false;
        cout << "ERROR: Unable to read/set south arrival distribution" << endl;
      }
    }

    if (success)
    {
      paramF >> percentCarsAdvanceOnYellow;
      if (paramF.fail() || 
          percentCarsAdvanceOnYellow < 0 ||
          percentCarsAdvanceOnYellow > 100)
      {
        success = false;
        cout << "ERROR: Unable to read/set percentage yellow advance" << endl;
      }

      //Use the specified seed to seed the random number generator
      setSeed(randomSeedVal);
    }

    paramF.close();
  }

  //Let the caller know whether things went well or not by printing the
  if (!success)
  {
    cout << "ERROR: Parameter file was NOT read in successfully, so the " <<
            "simulation is NOT setup properly!" << endl;
    isSetupProperly = false;
  }
  else
  {
    cout << "Parameters read in successfully - simulation is ready!" << endl;
    isSetupProperly = true;
  }
}

void IntersectionSimulationClass::printParameters() const
{
  cout << "===== Begin Simulation Parameters =====" << endl;
  if (!isSetupProperly)
  {
    cout << "  Simulation is not yet properly setup!" << endl;
  }
  else
  {
    cout << "  Random generator seed: " << randomSeedVal << endl;
    cout << "  Simulation end time: " << timeToStopSim << endl;

    cout << "  East-West Timing -" <<
            " Green: " << eastWestGreenTime << 
            " Yellow: " << eastWestYellowTime <<
            " Red: " << getEastWestRedTime() << endl;

    cout << "  North-South Timing -" <<
            " Green: " << northSouthGreenTime << 
            " Yellow: " << northSouthYellowTime <<
            " Red: " << getNorthSouthRedTime() << endl;

    cout << "  Arrival Distributions:" << endl;
    cout << "    East - Mean: " << eastArrivalMean << 
            " StdDev: " << eastArrivalStdDev << endl;
    cout << "    West - Mean: " << westArrivalMean << 
            " StdDev: " << westArrivalStdDev << endl;
    cout << "    North - Mean: " << northArrivalMean << 
            " StdDev: " << northArrivalStdDev << endl;
    cout << "    South - Mean: " << southArrivalMean << 
            " StdDev: " << southArrivalStdDev << endl;

    cout << "  Percentage cars advancing through yellow: " <<
            percentCarsAdvanceOnYellow << endl;
  }
  cout << "===== End Simulation Parameters =====" << endl;
}

void IntersectionSimulationClass::scheduleArrival(
     const string &travelDir
     )
{
  int arrivalTime;
  
  if (travelDir == EAST_DIRECTION)
  {
    arrivalTime = getPositiveNormal(eastArrivalMean, eastArrivalStdDev);
    EventClass newEvent(currentTime + arrivalTime, EVENT_ARRIVE_EAST);
    eventList.insertValue(newEvent);
    cout << "Time: " << currentTime << " Scheduled " << newEvent << endl;
  }
  else if (travelDir == WEST_DIRECTION)
  {
    arrivalTime = getPositiveNormal(westArrivalMean, westArrivalStdDev);
    EventClass newEvent(currentTime + arrivalTime, EVENT_ARRIVE_WEST);
    eventList.insertValue(newEvent);
    cout << "Time: " << currentTime << " Scheduled " << newEvent << endl;
  }
  else if (travelDir == NORTH_DIRECTION)
  {
    arrivalTime = getPositiveNormal(northArrivalMean, northArrivalStdDev);
    EventClass newEvent(currentTime + arrivalTime, EVENT_ARRIVE_NORTH);
    eventList.insertValue(newEvent);
    cout << "Time: " << currentTime << " Scheduled " << newEvent << endl;
  }
  else if (travelDir == SOUTH_DIRECTION)
  {
    arrivalTime = getPositiveNormal(southArrivalMean, southArrivalStdDev);
    EventClass newEvent(currentTime + arrivalTime, EVENT_ARRIVE_SOUTH);
    eventList.insertValue(newEvent);
    cout << "Time: " << currentTime << " Scheduled " << newEvent << endl;
  }
}

void IntersectionSimulationClass::scheduleLightChange(
     )
{
  if (currentLight == LIGHT_GREEN_EW)
  {
    EventClass newEvent(currentTime + eastWestGreenTime, EVENT_CHANGE_YELLOW_EW);
    eventList.insertValue(newEvent);
    cout << "Time: " << currentTime << " Scheduled " << newEvent << endl;
  }
  else if (currentLight == LIGHT_YELLOW_EW)
  {
    EventClass newEvent(currentTime + eastWestYellowTime, EVENT_CHANGE_GREEN_NS);
    eventList.insertValue(newEvent);
    cout << "Time: " << currentTime << " Scheduled " << newEvent << endl;
  }
  else if (currentLight == LIGHT_GREEN_NS)
  {
    EventClass newEvent(currentTime + northSouthGreenTime, EVENT_CHANGE_YELLOW_NS);
    eventList.insertValue(newEvent);
    cout << "Time: " << currentTime << " Scheduled " << newEvent << endl;
  }
  else if (currentLight == LIGHT_YELLOW_NS)
  {
    EventClass newEvent(currentTime + northSouthYellowTime, EVENT_CHANGE_GREEN_EW);
    eventList.insertValue(newEvent);
    cout << "Time: " << currentTime << " Scheduled " << newEvent << endl;
  }
}

bool IntersectionSimulationClass::handleNextEvent(
     )
{
  EventClass currentEvent;
  eventList.removeFront(currentEvent);
  currentTime = currentEvent.getTimeOccurs();

  if (currentTime > timeToStopSim)
  {
    cout << "\n" << "Next event occurs AFTER the simulation end time ("
         << currentEvent << ")!" << endl;
    return false;
  }
  
  cout << "\n" << "Handling " << currentEvent << endl;

  if (currentEvent.getType() == EVENT_ARRIVE_EAST)
  {
    CarClass newCar(EAST_DIRECTION, currentTime);
    eastQueue.enqueue(newCar);
    cout << "Time: " << currentTime << " Car #" << newCar.getId() 
         << " arrives east-bound - queue length: "
         << eastQueue.getNumElems() << endl;
    scheduleArrival(EAST_DIRECTION);
  }

  else if (currentEvent.getType() == EVENT_ARRIVE_WEST)
  {
    CarClass newCar(WEST_DIRECTION, currentTime);
    westQueue.enqueue(newCar);
    cout << "Time: " << currentTime << " Car #" << newCar.getId() 
         << " arrives west-bound - queue length: " 
         << westQueue.getNumElems() << endl;
    scheduleArrival(WEST_DIRECTION);
  }

  else if (currentEvent.getType() == EVENT_ARRIVE_NORTH)
  {
    CarClass newCar(NORTH_DIRECTION, currentTime);
    northQueue.enqueue(newCar);
    cout << "Time: " << currentTime << " Car #" << newCar.getId() 
         << " arrives north-bound - queue length: " 
         << northQueue.getNumElems() << endl;
    scheduleArrival(NORTH_DIRECTION);
  }

  else if (currentEvent.getType() == EVENT_ARRIVE_SOUTH)
  {
    CarClass newCar(SOUTH_DIRECTION, currentTime);
    southQueue.enqueue(newCar);
    cout << "Time: " << currentTime << " Car #" << newCar.getId() 
         << " arrives south-bound - queue length: " 
         << southQueue.getNumElems() << endl;
    scheduleArrival(SOUTH_DIRECTION);
  }

  else if (currentEvent.getType() == EVENT_CHANGE_YELLOW_EW)
  {
    cout << "Advancing cars on east-west green" << endl;

    CarClass advancingCar;
    int numEastCar = 0;  // number of cars advancing in the east and west
    int numWestCar = 0;
    currentLight = LIGHT_YELLOW_EW;

    while (eastQueue.getNumElems() > 0 && numEastCar < eastWestGreenTime)
    {
      eastQueue.dequeue(advancingCar);
      cout << "  Car #" << advancingCar.getId() 
           << " advances east-bound" << endl;
      numEastCar++;
      numTotalAdvancedEast++;
    }

    while (westQueue.getNumElems() > 0 && numWestCar < eastWestGreenTime)
    {
      westQueue.dequeue(advancingCar);
      cout << "  Car #" << advancingCar.getId() 
           << " advances west-bound" << endl;
      numWestCar++;
      numTotalAdvancedWest++;
    }

    cout << "East-bound cars advanced on green: " << numEastCar
         << " Remaining queue: " << eastQueue.getNumElems() << endl;
    cout << "West-bound cars advanced on green: " << numWestCar
         << " Remaining queue: " << westQueue.getNumElems() << endl;
    scheduleLightChange();
  }

  else if (currentEvent.getType() == EVENT_CHANGE_GREEN_NS)
  {
    cout << "Advancing cars on east-west yellow" << endl;
    
    CarClass advanceCar;
    int numEastCar = 0;
    int numWestCar = 0;
    currentLight = LIGHT_GREEN_NS;
    int advanceEastYellow = getUniform(1, 100);

    while(advanceEastYellow <= percentCarsAdvanceOnYellow 
            && eastQueue.getNumElems() > 0 
            && numEastCar < eastWestYellowTime)
    {     
      cout << "  Next east-bound car will advance on yellow" << endl;
      eastQueue.dequeue(advanceCar);
      cout << "  Car #" << advanceCar.getId() 
           << " advances east-bound" << endl;
      
      numEastCar++;
      numTotalAdvancedEast++;
      advanceEastYellow = getUniform(1, 100);
    }

    if (eastQueue.getNumElems() == 0)
    {
      cout << "  No east-bound cars waiting to advance on yellow" << endl;
    }
    else if (advanceEastYellow > percentCarsAdvanceOnYellow)
    {
      cout << "  Next east-bound car will NOT advance on yellow" << endl;
    }
    
    int advanceWestYellow = getUniform(1, 100);
    while(advanceWestYellow <= percentCarsAdvanceOnYellow 
            && westQueue.getNumElems() > 0 
            && numWestCar < eastWestYellowTime)
    {     
      cout << "  Next west-bound car will advance on yellow" << endl;
      westQueue.dequeue(advanceCar);
      cout << "  Car #" << advanceCar.getId() 
           << " advances west-bound" << endl;
      
      numWestCar++;
      numTotalAdvancedWest++;
      advanceWestYellow = getUniform(1, 100);
    }

    if (westQueue.getNumElems() == 0)
    {
      cout << "  No west-bound cars waiting to advance on yellow" << endl;
    }
    else if (advanceWestYellow > percentCarsAdvanceOnYellow)
    {
      cout << "  Next west-bound car will NOT advance on yellow" << endl;
    }
    
    cout << "East-bound cars advanced on green: " << numEastCar
         << " Remaining queue: " << eastQueue.getNumElems() << endl;
    cout << "West-bound cars advanced on green: " << numWestCar
         << " Remaining queue: " << westQueue.getNumElems() << endl;
    scheduleLightChange();
  }

  else if (currentEvent.getType() == EVENT_CHANGE_YELLOW_NS)
  {
    cout << "Advancing cars on north-south green" << endl;

    CarClass advancingCar;
    int numNorthCar = 0;
    int numSouthCar = 0;
    currentLight = LIGHT_YELLOW_NS;

    while (northQueue.getNumElems() > 0 && numNorthCar < northSouthGreenTime)
    {
      northQueue.dequeue(advancingCar);
      cout << "  Car #" << advancingCar.getId() 
           << " advances north-bound" << endl;
      numNorthCar++;
      numTotalAdvancedNorth++;
    }

    while (southQueue.getNumElems() > 0 && numSouthCar < northSouthGreenTime)
    {
      southQueue.dequeue(advancingCar);
      cout << "  Car #" << advancingCar.getId() 
           << " advances south-bound" << endl;
      numSouthCar++;
      numTotalAdvancedSouth++;
    }
    
    cout << "North-bound cars advanced on green: " << numNorthCar
         << " Remaining queue: " << northQueue.getNumElems() << endl;
    cout << "South-bound cars advanced on green: " << numSouthCar
         << " Remaining queue: " << southQueue.getNumElems() << endl;
    scheduleLightChange();
  }

  else if (currentEvent.getType() == EVENT_CHANGE_GREEN_EW)
  {
    cout << "Advancing cars on north-south yellow" << endl;
    
    CarClass advanceCar;
    int numNorthCar = 0;
    int numSouthCar = 0;
    currentLight = LIGHT_GREEN_EW;
    int advanceNorthYellow = getUniform(1, 100);

    while(advanceNorthYellow <= percentCarsAdvanceOnYellow 
            && northQueue.getNumElems() > 0 
            && numNorthCar < northSouthYellowTime)
    {     
      cout << "  Next north-bound car will advance on yellow" << endl;
      northQueue.dequeue(advanceCar);
      cout << "  Car #" << advanceCar.getId() 
           << " advances north-bound" << endl;
      
      numNorthCar++;
      numTotalAdvancedNorth++;
      advanceNorthYellow = getUniform(1, 100);
    }

    if (northQueue.getNumElems() == 0)
    {
      cout << "  No north-bound cars waiting to advance on yellow" << endl;
    }
    else if (advanceNorthYellow > percentCarsAdvanceOnYellow)
    {
      cout << "  Next north-bound car will NOT advance on yellow" << endl;
    }
    
    int advanceSouthYellow = getUniform(1, 100);
    while(advanceSouthYellow <= percentCarsAdvanceOnYellow 
            && southQueue.getNumElems() > 0
            && numSouthCar <= northSouthYellowTime)
    {     
      cout << "  Next south-bound car will advance on yellow" << endl;
      southQueue.dequeue(advanceCar);
      cout << "  Car #" << advanceCar.getId() 
           << " advances south-bound" << endl;
      
      numSouthCar++;
      numTotalAdvancedSouth++;
      advanceSouthYellow = getUniform(1, 100);
    }

    if (southQueue.getNumElems() == 0)
    {
      cout << "  No south-bound cars waiting to advance on yellow" << endl;
    }
    else if (advanceSouthYellow > percentCarsAdvanceOnYellow)
    {
      cout << "  Next south-bound car will NOT advance on yellow" << endl;
    }

    cout << "North-bound cars advanced on green: " << numNorthCar
         << " Remaining queue: " << northQueue.getNumElems() << endl;
    cout << "South-bound cars advanced on green: " << numSouthCar
         << " Remaining queue: " << southQueue.getNumElems() << endl;
    scheduleLightChange();
  }
  
  maxEastQueueLength = (maxEastQueueLength > eastQueue.getNumElems()) ? 
                          maxEastQueueLength : eastQueue.getNumElems();
  maxWestQueueLength = (maxWestQueueLength > westQueue.getNumElems()) ? 
                          maxWestQueueLength : westQueue.getNumElems();
  maxNorthQueueLength = (maxNorthQueueLength > northQueue.getNumElems()) ? 
                          maxNorthQueueLength : northQueue.getNumElems();
  maxSouthQueueLength = (maxSouthQueueLength > southQueue.getNumElems()) ? 
                          maxSouthQueueLength : southQueue.getNumElems();
  return true;
}

void IntersectionSimulationClass::printStatistics(
     ) const
{
  cout << "===== Begin Simulation Statistics =====" << endl;
  cout << "  Longest east-bound queue: " << maxEastQueueLength << endl;
  cout << "  Longest west-bound queue: " << maxWestQueueLength << endl;
  cout << "  Longest north-bound queue: " << maxNorthQueueLength << endl;
  cout << "  Longest south-bound queue: " << maxSouthQueueLength << endl;
  cout << "  Total cars advanced east-bound: " <<
          numTotalAdvancedEast << endl;
  cout << "  Total cars advanced west-bound: " <<
          numTotalAdvancedWest << endl;
  cout << "  Total cars advanced north-bound: " <<
          numTotalAdvancedNorth << endl;
  cout << "  Total cars advanced south-bound: " <<
          numTotalAdvancedSouth << endl;
  cout << "===== End Simulation Statistics =====" << endl;
}
