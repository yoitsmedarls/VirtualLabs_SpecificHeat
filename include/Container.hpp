#ifndef CONTAINER
#define CONTAINER

#include <memory>

#include "Liquid.hpp"
#include "Metal.hpp"

namespace vl
{
    /**
     * @author @yoitsmedarls
     * @brief  The base class for all objects designed to 'contain' other
     *         objects from the Liquid and Metal class.
     */
    class Container
    {
    protected: /** Properties *************************************************/
        double m_diameter;
        double m_height;
        double m_totalMass;
        double m_totalVolume;
        double m_availableVolume;
        double m_topSurfaceArea;
        std::shared_ptr<Liquid> m_liquid;
        std::shared_ptr<Metal> m_metal;

    public:
        bool containsLiquid = false;
        bool containsMetal = false;
        bool isInUse = false;

    public: /** Special member functions **************************************/
        /**
         * @brief   Construct a new Container object.
         * @details Default constructor, initializes every field with 0 or its
         *          equivalent
         */
        Container();

        /**
         * @brief   Construct a new Container object with supplied parameters
         * @details Constructor with arguments for the class fields. This
         *          constructor DOES NOT include parameters for the pointers to
         *          the Liquid and Metal objects inside the Container.
         *
         * @param diameter
         * @param height
         */
        Container(double diameter,
                  double height);

        /**
         * @brief   Construct a new Container object with supplied parameters
         * @details Constructor with arguments for the class fields. This
         *          constructor includes parameters for the pointers to
         *          the Liquid and Metal objects inside the Container
         *
         * @param diameter
         * @param height
         * @param liquid
         * @param metal
         */
        Container(double diameter,
                  double height,
                  std::shared_ptr<Liquid> liquid,
                  std::shared_ptr<Metal> metal);

        /**
         * @brief   Copy constructor of the Container class.
         * @details Constructs a Container object as a copy of another one.
         *
         * @param copy A pre-existing, pre-initialized Container object that is
         *             passed by reference.
         */
        Container(const Container &copy);

        /**
         * @brief Destroy the Container object
         */
        ~Container();

    public: /** Operator overloads ********************************************/
        /**
         * @brief   Copy assignment operator of the Container class.
         * @details Handles cases where you assign a blank Container object
         *          with another pre-existing Container object. It prevents
         *          extra copies.
         *
         * @param copy
         * @return Container&
         */
        Container &operator=(const Container &copy);

    public: /** Getters and Setters *******************************************/
        double getDiameter();
        void setDiameter(double diameter);

        double getHeight();
        void setHeight(double height);

        double getTotalMass();

        double getTotalVolume();

        double getAvailableVolume();

        double getTopSurfaceArea();

        std::shared_ptr<Liquid> getContainedLiquid();
        void addLiquid(std::shared_ptr<Liquid> liquid);
        void removeContainedLiquid();

        std::shared_ptr<Metal> getContainedMetal();
        void addMetal(std::shared_ptr<Metal> metal);
        void removeContainedMetal();

    public: /** Other member functions ****************************************/
        /**
         * @brief   Calculates topSurfaceArea from the Container's
         *          diameter and height values.
         * @details Updates the topSurfaceArea upon changes to the other
         *          aforementioned fields. Usually called inside other
         *          methods that change the value of fields (i.e. setters).
         */
        void updateTopSurfaceArea();

        /**
         * @brief   Calculates volume from the Container's
         *          diameter and height values.
         * @details Updates the volume changes to the other aforementioned
         *          fields. Usually called inside other methods that change
         *          the value of fields (i.e. setters).
         */
        void updateVolume();
    };

} // namespace vl

#endif