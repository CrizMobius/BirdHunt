#ifndef _DUCKS_CPLAYER_H_
#define _DUCKS_CPLAYER_H_

#include "cdeadline.h"
#include "cstate.h"
#include "matrix.h"
#include <vector>

namespace ducks
{

class CPlayer
{
	public:
			
		/*!	\brief		constructor
		*	\details	There is no data in the beginning, so not much should be done here.
		*/
		CPlayer();

		/*!	\brief		shoot!
		 *	\details	This is the function where you should do all your work.
		 *				you will receive a variable pState, which contains information about all ducks,
		 *				both dead and alive. Each duck contains all past actions.
		 *				The state also contains the scores for all players and the number of
		 *				time steps elapsed since the last time this function was called.
		 *				Check their documentation for more information.
		 *	\param	pState	the state object
		 *	\param	pDue	time before which we must have returned. To check how much 
		 * 					time we have left you can use \p pDue.RemainingUntil(), 
		 *					which returns the remaining time in milliseconds.
		 *	\return 		the position we want to shoot at, or cDontShoot if we prefer to pass
		 */
		CAction Shoot(const CState &pState,const CDeadline &pDue);

		/*!	‪\brief		guess the species!
		 *	\details	This function will be called at the end of the game, to give you
		 * 				a chance to identify the species of the surviving ducks for extra
		 * 				points. For each alive duck in the vector, you must call 
		 *				the SetSpecies function,
		 * 				passing one of the ESpecies constants as a parameter
		 *	\param	pDucks	the vector of all ducks. You must identify only the ones that are alive
		 *	\param	pDue	time before which we must have returned
		 */
		void Guess(std::vector<CDuck> &pDucks,const CDeadline &pDue);

		/*!	\brief	This function will be called whenever you hit a duck.
		 *	\param	pDuck the duck index
		 *	\param	pSpecies the species of the duck 
		 *			(it will also be set for this duck in pState from now on)
		 */
		void Hit(int pDuck,ESpecies pSpecies);
};

/*namespace ducks*/ }

#endif
