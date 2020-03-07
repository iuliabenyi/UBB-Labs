#pragma once
#include "Domain.h"
#include "Controller.h"

enum opType
{
	opAdd,
	opRemove,
	opUpdateType,
	opUpdateAddress,
	opUpdateSurface,
	opUpdatePrice
};

struct operation
{
	int operationType, indx;
	struct Offer oldOffer;
	struct Offer currOffer;

} undoOp[1000], redoOp[1000];

int undoLength;
int redoLength;

int undoOperation();
int redoOperation();
