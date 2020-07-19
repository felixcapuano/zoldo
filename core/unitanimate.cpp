#include "unitanimate.h"

#include <math.h>

#include "tools/elementfactory.h"
#include "core/projectile.h"
#include "elements/projectile/testprojectile.h"


UnitAnimate::UnitAnimate()
{

    setType(UNIT_ANIMATE);

    // angle de rotation of the image
    currentRotation = 0;

    // direction where the unit look
    directionVector[0] = 0;
    directionVector[1] = -1;

    setCenterAsReferencial();

    // distance
    targetDistance = 0;

    // interval between each shoot
    shootRate = 500;
    shootTimer = new QTimer(this);
    connect(shootTimer, SIGNAL(timeout()), this, SLOT(shoot()));
    shootTimer->start(shootRate);

    // projectile shooted
    projectileList = new QList<Projectile*>();

    // projectile shooted
    projectileName = TEST_PROJECTILE;
}

UnitAnimate::~UnitAnimate()
{
    delete projectileList;
}

void UnitAnimate::lockTarget(const Unit * const target)
{
    if (!target->isDead()) {
        int newDirX = target->x() - this->x();
        int newDirY = target->y() - this->y();

        targetDistance = sqrt(newDirX * newDirX + newDirY * newDirY);
        currentRotation = acos( -newDirY /  targetDistance) * 180/3.14;

        if(newDirX < 0)
            currentRotation *= -1;

        setRotation(currentRotation + getDefaultRotation());

        directionVector[0] = newDirX / targetDistance;
        directionVector[1] = newDirY / targetDistance;
    }
}

int UnitAnimate::getCurrentRotation() const
{
    return currentRotation;
}

void UnitAnimate::shoot()
{
    // seting a default projectile
    fire();
}

void UnitAnimate::fire()
{
    Projectile * proj = dynamic_cast<Projectile*>(ElementFactory::create(projectileName));
    proj->setOwner(this);

    proj->setPos(this->x(), this->y());

    proj->setHorizontalMov(directionVector[0]);
    proj->setVerticalMov(directionVector[1]);

    proj->setDefaultRotation(currentRotation);

    projectileList->append(proj);
}

float UnitAnimate::getTargetDistance() const
{
    return targetDistance;
}

const float* UnitAnimate::getDirectionVector() const
{
    return directionVector;
}

QList<Projectile*> * UnitAnimate::getProjectileList() const
{
    return projectileList;
}

int UnitAnimate::getShootRate() const
{
    return shootRate;
}

void UnitAnimate::setShootRate(int value)
{
    shootRate = value;
}
