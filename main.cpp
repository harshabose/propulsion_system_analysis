#include <iostream>
#include <pybind11/embed.h>
#include <pybind11/stl.h>
#include "include/propulsion_system.h"

int main()
{
    static constexpr float altitude = 3941.37869f;
    static constexpr float velocity = 61.92303103f;
    static constexpr float angle_of_attack = 3.080505517f;
    static constexpr float thrust_required = 3687.74f;
    static constexpr float gamma = 4.695810749f;
    static size_t opt_count = 0;

    static constexpr size_t number_of_propellers_ = 4;
    static constexpr size_t number_of_blades_ = 3;
    static constexpr float radius_ = 1.0f;
    static constexpr float chord_ = 0.3f;

    pybind11::initialize_interpreter();
    const auto atmosphere = std::make_shared<operationalPoint_h::operationalPoint>(altitude, velocity, 0, angle_of_attack);
    auto propulsion_system = PROPULSION_SYSTEM_H::propulsion_system(atmosphere.get(), true, true);

    propulsion_system.set_propeller_root_pitch(0.0f);
    propulsion_system.set_propeller_RPM(100.0f);

    propulsion_system.update_propulsion_system_design (
        number_of_propellers_, radius_, number_of_blades_, chord_,
        std::vector<float>{1.0f},
        std::vector<float>{0.0f});

    propulsion_system.set_total_thrust_required(thrust_required);
    propulsion_system.simulate_propulsion_system();
    std::cout << "ANALYSIS DONE....!!" << std::endl << std::endl;
    std::cout << "RESULTS:" << std::endl;
    std::cout << "number of propeller: " << number_of_propellers_ << "; radius: " << radius_ << "; number_of_blades: " << number_of_blades_ << "; chord: " << chord_;
    std::cout << " Root pitch: " << propulsion_system.get_propeller_root_pitch() << ", Root RPM: " << propulsion_system.get_propeller_RPM() << " -> power required to run the propulsion system: " << propulsion_system.total_POWER_required << std::endl;

    pybind11::finalize_interpreter();
}
