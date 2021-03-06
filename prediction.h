#ifndef PREDICTION_H
#define PREDICTION_H

#include "matrix.h"
#include "cduck.h"

#include<vector>
#include<map>

class Prediction
{
	public:
		Prediction(const ducks::CDuck & refDuck, const Matrix & initStates, const Matrix & states, const Matrix & obsStates);
		void calculate();
		void print() const;
		void printDuckSequence() const;
		std::size_t getNextV() const { return nextV;}
		std::size_t getNextH() const { return nextH;}
	private:
		static std::map<std::pair<ducks::EAction, ducks::EAction>, std::size_t> observation;
		
		// HMM functions
		std::size_t getObservedState(std::size_t t);
		void calculateAlpha();
		void calculateBeta();
		void calculateYAndDiGamma();
		void calculateLogProb();
		void reEstimate();
		void makePrediction();
		
		// Bird variables
		const ducks::CDuck & duck;
			
		// HMM variables
		std::size_t nextV;
		std::size_t nextH;
		std::size_t nextState;
		std::size_t nextObservation;
		std::vector<float> c;
		float denom;
		float numer;
		float logProb;
		float oldLogProb;
		std::size_t maxIter;
		Matrix init;
		Matrix a;
		Matrix b;
		std::vector<Matrix> alpha;
		std::vector<Matrix> beta;
		std::vector<Matrix> diGamma;
		std::vector<Matrix> gamma;
};
#endif
