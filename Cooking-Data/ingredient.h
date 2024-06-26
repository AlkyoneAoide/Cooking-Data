#ifndef INGREDIENT_H
#define INGREDIENT_H

#include "ingredienttype.h"

#include <QLabel>
#include <QPoint>
#include <QSize>

class Ingredient {
private:
    ///
    /// \brief ID an ID unique to this instance.
    ///
    int ID;

    ///
    /// \brief globalLatestID the latest ID of all Ingredients.
    ///
    static int globalLatestID;

    IngredientType INGREDIENT_TYPE;

    ///
    /// \brief dimensions The dimension of the ingredient in meters. Should be
    ///                   0.0125 times (divide by 80) the dimension of the texture.
    ///
    QSizeF dimensions;

    ///
    /// \brief weight The weight of the Ingredient in kg
    ///
    double weight;

    ///
    /// \brief friction [0, 1]
    ///
    double friction = 0.8;

    ///
    /// \brief restitution Bounciness, [0, 1].
    ///
    double restitution = 0.1;

    ///
    /// \brief texture The dimension of the texture should be double that of
    ///                the Ingredient's dimension.
    ///
    QPixmap texture;

    ///
    /// \brief position The position of the Ingredient in meters.
    ///
    QPointF position;

    ///
    /// \brief angle The angle of the ingredient in degrees.
    ///
    double angle;

public:

    Ingredient();
    Ingredient(QPointF positon);
    Ingredient(IngredientType type, QSizeF dimension, double weight,
               QPixmap texture, QPointF position, double angle);
    Ingredient(IngredientType type, QSizeF dimension, double weight,
               double friction, double restitution, QPixmap texture,
               QPointF position, double angle);
    ~Ingredient();

    ///
    /// \brief Ingredient Create a copy of the Ingredient passed in with a new
    ///                   ID.
    /// \param rhs
    ///
    Ingredient(const Ingredient& rhs);

    ///
    /// \brief operator = Assign other to the Ingredient with a new ID as these
    ///                   two Ingredients have different memory.
    /// \param other the other Ingredient
    /// \return the Ingredient
    ///
    Ingredient& operator=(const Ingredient& other);

    ///
    /// \brief operator == Evaluate whether the lhs and rhs are equivalent.
    /// \param rhs
    /// \return
    ///
    bool operator==(const Ingredient& rhs) const;

    int getID() const { return ID; }
    IngredientType getIngredientType() const { return INGREDIENT_TYPE; }
    QSizeF getDimensions() const { return dimensions; }
    double getWeight() const { return weight; }
    QPixmap getTexture() const;
    double getFriction() const { return friction; }
    double getRestitution() const { return restitution; }
    QPointF getPosition() const { return position; }

    ///
    /// \brief getAngle Get the angle in degrees.
    /// \return the angle in degrees
    ///
    double getAngle() const { return angle; }

    void setPosition(QPointF newPosition) { position = newPosition; }
    void setDimensions(QSizeF newDimensions) { dimensions = newDimensions; }
    void setAngle(double newAngle) { angle = newAngle; }
};

// This had to be inline or it will not compile.
///
/// \brief qHash Return a hash of the Ingredient passed in.
/// \param ingredient the ingredient to hash
/// \return the hash
///
inline size_t qHash(const Ingredient& ingredient) {
    return ingredient.getID();
}

#endif // INGREDIENT_H
