#include "UndoRedo.h"	 
#include "Controller.h"

int undoOperation()
{
	/*
		Performs the undo operation
	*/
	if (undoLength == 0)
		return -1;

	switch (undoOp[undoLength - 1].operationType)
	{
	case opAdd:
	{
		removeOffer(undoOp[undoLength - 1].oldOffer.address, -1);
	}
	break;

	case opRemove:
	{
		insertAtPos(offers, undoOp[undoLength - 1].indx, undoOp[undoLength - 1].oldOffer);
	}
	break;

	case opUpdateAddress:
	{
		updateAddress(undoOp[undoLength - 1].indx, undoOp[undoLength - 1].oldOffer.address, -1);
	}
	break;

	case opUpdatePrice:
	{
		updatePrice(undoOp[undoLength - 1].indx, undoOp[undoLength - 1].oldOffer.price, -1);
	}
	break;

	case opUpdateSurface:
	{
		updateSurface(undoOp[undoLength - 1].indx, undoOp[undoLength - 1].oldOffer.surface, -1);
	}
	break;

	case opUpdateType:
	{
		updateType(undoOp[undoLength - 1].indx, undoOp[undoLength - 1].oldOffer.type, -1);
	}
	break;

	default:
		return -1;
		break;
	}

	redoOp[redoLength].indx = undoOp[undoLength - 1].indx;
	redoOp[redoLength].oldOffer = undoOp[undoLength - 1].oldOffer;
	redoOp[redoLength].currOffer = undoOp[undoLength - 1].currOffer;
	redoOp[redoLength].operationType = undoOp[undoLength - 1].operationType;

	++redoLength;
	--undoLength;

	return 1;
}


int redoOperation()
{
	/*
		Performs the redo operation
	*/
	if (redoLength == 0)
		return -1;

	switch (undoOp[redoLength - 1].operationType)
	{
	case opAdd:
	{
		addOffer(redoOp[redoLength - 1].oldOffer.type, redoOp[redoLength - 1].oldOffer.address, redoOp[redoLength - 1].oldOffer.surface, redoOp[redoLength - 1].oldOffer.price, 1);
	}
	break;

	case opRemove:
	{
		removeOffer(redoOp[redoLength - 1].oldOffer.address, 1);
	}
	break;

	case opUpdateAddress:
	{
		updateAddress(redoOp[redoLength - 1].indx, redoOp[redoLength - 1].currOffer.address, 1);
	}
	break;

	case opUpdatePrice:
	{
		updatePrice(redoOp[redoLength - 1].indx, redoOp[redoLength - 1].currOffer.price, 1);
	}
	break;

	case opUpdateSurface:
	{
		updateSurface(redoOp[redoLength - 1].indx, redoOp[redoLength - 1].currOffer.surface, 1);
	}
	break;

	case opUpdateType:
	{
		updateType(redoOp[redoLength - 1].indx, redoOp[redoLength - 1].currOffer.type, 1);
	}
	break;

	default:
		return -1;
		break;
	}

	--redoLength;
	return 1;
}