#pragma once

//INCLUDES
#include "DrawDebugHelpers.h"

// DEFINES
#define DRAW_RED_SPHERE(Location) if (GetWorld()) \
			DrawDebugSphere(GetWorld(), Location, 25.f, 6, FColor::Red, true);
#define DRAW_RED_LINE(StartLocation, EndLocation) if (GetWorld()) \
			DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f);
#define DRAW_RED_POINT(Location) if (GetWorld()) \
			DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Red, true);
#define DRAW_RED_VECTOR(StartLocation, EndLocation) if (GetWorld()) \
			DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f); \
			DrawDebugPoint(GetWorld(), EndLocation, 15.f, FColor::Red, true);