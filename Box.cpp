#include "Box.h"

bool Box::Equals(Box other)
{
	return Row == other.Row &&
		Column == other.Column;
}