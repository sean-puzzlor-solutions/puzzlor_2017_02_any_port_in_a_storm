// puzzlorfeb2017anyportinastorm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <ilcplex\cplex.h>
#include <ilcplex\ilocplex.h>
#include <ilconcert\iloenv.h>
#include <ilconcert\ilomodel.h>

#include <iostream>
#include <algorithm>
#include <stdio.h>

ILOSTLBEGIN

int main()
{
	// data
	int delta_cd[3][3] = { {1,2,3}, {3,2,2}, {2,1,1} };		// distance from cluster c to dock d
	int n_c[3] = { 8,5,7 };									// number of boats in cluster c
	int q_d[3] = { 4,7,9 };									// number of quays in dock d

	IloEnv env;												// creating the ilo environment

	IloModel model(env);	
	
	IloArray<IloNumVarArray> x(env);						// decision variables
	//generating decision variables
	for (int i = 0; i < 3; i++)
		x.add(IloNumVarArray(env, 3, 0, IloInfinity));

	// objective function
	IloExpr totalDist(env);
	for (int c = 0; c < 3; c++)	{
		for (int d = 0; d < 3; d++)	{
			totalDist += delta_cd[c][d] * x[c][d];
		}
	}
	model.add(IloMaximize(env, totalDist));

	//creating constraints 2
	for (int c = 0; c < 3; c++) {
		IloExpr aux(env);
		for (int d = 0; d < 3; d++) {
			aux += x[c][d];
		}
		model.add(aux == n_c[c]);
	}

	//creating constraints 3
	for (int d = 0; d < 3; d++) {
		IloExpr aux(env);
		for (int c = 0; c < 3; c++) {
			aux += x[c][d];
		}
		model.add(aux == q_d[d]);
	}

	IloCplex cplex(model);
	cplex.exportModel("anyPort.LP");

	cplex.solve();

	env.out() << "Solution Status: \t" << cplex.getStatus() << std::endl;
	env.out() << "Total Profit:    \t" << cplex.getObjValue() << std::endl;

	int t;
	std::cin >> t;


	//env.end;

    return 0;
}