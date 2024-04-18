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
    QPointF position;

    ///
    /// \brief dimensions The dimension of the ingredient in inches. Should be
    ///                   half of the dimension of the texture.
    ///
    QSize dimensions;

    ///
    /// \brief angle The angle of the ingredient in degrees.
    ///
    double angle;

    ///
    /// \brief texture The dimension of the texture should be double that of
    ///                the Ingredient's dimension.
    ///
    QPixmap texture;

public:

    Ingredient();
    Ingredient(IngredientType type, QPointF position, QSize dimension, double angle, QPixmap texture);
    ~Ingredient();

    ///
    /// \brief Ingredient Create a copy of the Ingredient passed in with a new ID.
    /// \param rhs
    ///
    Ingredient(const Ingredient& rhs);

    ///
    /// \brief operator = Assign other to the Ingredient with a new ID.
    /// \param other the other Ingredient
    /// \return the
    ///
    Ingredient& operator=(const Ingredient& other);

    ///
    /// \brief operator == Evaluate whether the lhs and rhs are equivalent.
    /// \param rhs
    /// \return
    bool operator==(const Ingredient& rhs) const;

    int getID() const { return ID; }
    IngredientType getIngredientType() const { return INGREDIENT_TYPE; }
    QPointF getPosition() const { return position; }
    QSize getDimensions() const { return dimensions; }

    ///
    /// \brief getAngle Get the angle in degrees.
    /// \return the angle in degrees
    ///
    double getAngle() const { return angle; }
    QPixmap getTexture() const { return texture; }

    ///
    /// \brief getRadius Get the radius of the Ingredient, which is half of the
    ///                  larger value between width and height.
    /// \return the radius
    ///
    double getRadius() const;

    void setPosition(QPointF newPosition) { position = newPosition; }
    void setDimensions(QSize newDimensions) { dimensions = newDimensions; }
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
