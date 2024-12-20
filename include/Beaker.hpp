#ifndef BEAKER
#define BEAKER

#include "Container.hpp"

namespace vl
{
    /**
     * @author @yoitsmedarls
     * @brief  A child of the Container class. Beaker is a non-isolated
     *         container with methods for Beaker-specific tasks in the
     *         simulation.
     */
    class Beaker : public Container
    {
    public: /** Properties ***************************************************/
        bool isIsolated = false;

    public: /** Special member functions **************************************/
        Beaker();
        Beaker(double diameter,
               double height);
        Beaker(double diameter,
               double height,
               std::shared_ptr<Liquid> liquid,
               std::shared_ptr<Metal> metal);
        Beaker(const Beaker &copy);
        ~Beaker();

    public: /** Operator overloads ********************************************/
        Beaker &operator=(const Beaker &copy);

    public: /** Getters and Setters *******************************************/
        // getset

    public: /** Other member functions ****************************************/
        // others
    };

} // namespace vl

#endif