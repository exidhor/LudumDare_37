/*!
 * \file TriggerableObject.hpp
 * \brief Super class of all TriggerableObject
 * \brief A TriggerableObject object contains at least
 * \brief one method trigger
 * \author Aredhele
 * \version 0.1
 * \date 2016-01-02
 */

#ifndef DEF_TRIGGERABLE_OBJECT_HPP
#define DEF_TRIGGERABLE_OBJECT_HPP

#include <string>
#include <vector>

class TriggerableObject
{
	using usint = unsigned short int;

	public:
		// Constructor
		TriggerableObject();

		// Destructor
		virtual ~TriggerableObject();

		// Methods
		virtual void trigger(usint id) = 0;
		virtual void trigger(usint id,
		std::vector< std::string > v) = 0;
};

#endif // DEF_TRIGGERABLE_OBJECT_HPP