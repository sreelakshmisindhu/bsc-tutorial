// On lxplus you need to execute `source /cvmfs/sft.cern.ch/lcg/views/LCG_95/x86_64-centos7-gcc8-opt/setup.sh`
// in order to have a recent g++ version at hand.
// In this exercise you will mimic a very basic analysis workflow: Implement the data format for recorded particles
// and events. Then implement a more advanced data format for events, inheriting from the basic format but
// containing more high-level functionality suited to your analysis, i.e. select particles and calculate a certain
// quantity from it.

#include <iostream>
#include <math.h>
#include <vector>
#include <memory>
#include <functional>

// Step 1: Define a class 'Particle' which stores four quantities (type double):
// - the transverse momentum pt
// - the transverse angle phi
// - the pseudrapidity eta
// - a identification criterion representing the quality of the particle reconstruction id (will take values between 0.0=bad to 1.0=excellent)
// Make these attributes private but provide public access methods that return their values.
// Add two more methods that calculate the x- and the y-component of the momentum (Ãpx=pt*cos(phi), py=pt*sinphi)).
// Add a constructor that takes pt, phi, eta and id as arguments.
class Particle {
private:
    double _pt;
    //...
public:
    double pt() { return _pt; }
    //...
};

// Step 2: Define a class Event that stores the particles of an event. You need:
// - a vector of shared pointers to electrons
// - a vector of shared pointers to muons
// Both electrons and muons are stored as type Particle but are distinguished by storing them in different vectors.
// We use shared pointers of Particle (and not just Particle) so that we can create particle selections as new vectors
// without copying all the particle data.
// Add a method add_particle which fills particles to the event. Its first argument is a boolean stating wether the
// particle is a muon (or electron otherwise). The other arguments are pt, phi, eta and id of the particle.
class Event {
public:
    //...

    void add_particle(bool is_muon, double pt, double phi, double eta, double id){
        //...
    }
};

// --> step 3 see below

// Step 4: Write a new class ProcessedEvent inheriting from Event and extending it.
// Add a constructor that takes an instance of the base class to fill the given values (already done!).
// Add two new particle vectors for selected electrons and muons (we want to apply some selection on the id).
// Add a method for electrons and muons each that runs through the initial particle vector and adds only
// selected particles to the selection. The method should take a lambda (called f here) as argument, which can be inserted
// from outside to determine the selection criterion. It is supposed to return true or false. Accepting the lamda as
// argument requires some template syntax which is already applied for you.
// --> step 5 see below
// Step 6: The function deltaP_T_em is not yet well implemented. It should go through the selected electrons and muons,
// identify the with the largest pt each and then calculate length of the vectorial difference between the pts of the two.
// Use the px and py methods you defined before. Note that not every event contains at least one electron and one muon.
// Thus, the requested quantity is not always defined. Catch those events and assign a dummy value of -999.
/*class ProcessedEvent : public Event{
public:
    //...

    ProcessedEvent(Event e) : Event(e){};
    template<typename F>
    void select_electrons(F f){
        //...
    }
    template<typename F>
    void select_muons(F f){
        //...
    }
    double deltaP_T_em(){
        return 42.0;
    }
};*/

// This functions mimics a detector giving you some event data.
std::vector<Event> record_data(){
    std::vector<Event> events;
    events.push_back(Event());
    events.back().add_particle(true, 20.11, 4.23, 0.18, 0.88);
    events.back().add_particle(true, 31.09, 1.01, 2.62, 0.90);
    events.push_back(Event());
    events.back().add_particle(false, 9.53, 3.60, -1.44, 0.23);
    events.back().add_particle(true, 22.76, 0.25, 0.70, 0.78);
    events.push_back(Event());
    events.back().add_particle(false, 50.21, 5.89, 3.40, 0.10);
    events.back().add_particle(false, 16.74, 2.10, -2.85, 0.66);
    events.back().add_particle(false, 25.66, 0.54, -1.47, 0.73);
    events.back().add_particle(true, 16.67, 1.44, -3.11, 0.98);
    events.back().add_particle(true, 30.29, 2.68, 1.39, 0.87);
    return events;
}

// Step 3: Run the record_data function loading your events and cout some values for testing.
// --> step 4 see above
// Step 5: Fill a new vector of the ProcessedEvents, then define ID-cuts for electrons and muons (just
// comment in corresponding lines). Note that we did not yet run the selection process. Loop over the events
// and run the particle selection methods inserting the id requirement as a lambda. The lamda should capture
// the defined cut value, apply a comparison to the id value and return whether the id value exceeds the threshold.
// Add some test cout for checking the impact of your selection.
// --> step 6 see above
// Step 7: Calculate and print deltaP_T_em of the events. How many are reasonably filled and do you find 49.1297?
int main(){
    std::vector<Event> basic_events = record_data();
    // add test cout here

    //std::vector<ProcessedEvent> events(basic_events.begin(), basic_events.end());
    //double ele_id_cut = 0.5;
    //double mu_id_cut = 0.6;
    // add event loop
    return 0;
}
