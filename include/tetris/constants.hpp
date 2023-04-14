#ifndef CME_CONSTANT
#define CME_CONSTANT

#include "SFML/System/Vector2.hpp"

static inline constexpr unsigned int WINDOW_WIDTH = 480;
static inline constexpr unsigned int WINDOW_HEIGHT = 640;

static inline const sf::Vector2f TILE_SIZE = sf::Vector2f(20., 20.);

static inline const sf::Vector2f P1 = sf::Vector2f(1.0f, 1.0f);
static inline const sf::Vector2f P2 = sf::Vector2f(2.0f, 1.0f);
static inline const sf::Vector2f P3 = sf::Vector2f(2.0f, 2.0f);
static inline const sf::Vector2f P4 = sf::Vector2f(1.0f, 2.0f);
static inline const sf::Vector2f P5 = sf::Vector2f(1.2f, 1.2f);
static inline const sf::Vector2f P6 = sf::Vector2f(1.8f, 1.2f);
static inline const sf::Vector2f P7 = sf::Vector2f(1.8f, 1.8f);
static inline const sf::Vector2f P8 = sf::Vector2f(1.2f, 1.8f);

static inline const sf::Vector2f VF00 = sf::Vector2f(0., 0.);
static inline const sf::Vector2f VF10 = sf::Vector2f(1., 0.);
static inline const sf::Vector2f VF20 = sf::Vector2f(2., 0.);
static inline const sf::Vector2f VF30 = sf::Vector2f(3., 0.);
static inline const sf::Vector2f VF01 = sf::Vector2f(0., 1.);
static inline const sf::Vector2f VF11 = sf::Vector2f(1., 1.);
static inline const sf::Vector2f VF21 = sf::Vector2f(2., 1.);
static inline const sf::Vector2f VF31 = sf::Vector2f(3., 1.);
static inline const sf::Vector2f VF02 = sf::Vector2f(0., 2.);
static inline const sf::Vector2f VF12 = sf::Vector2f(1., 2.);
static inline const sf::Vector2f VF22 = sf::Vector2f(2., 2.);
static inline const sf::Vector2f VF32 = sf::Vector2f(3., 2.);
static inline const sf::Vector2f VF03 = sf::Vector2f(0., 2.);
static inline const sf::Vector2f VF13 = sf::Vector2f(1., 2.);
static inline const sf::Vector2f VF23 = sf::Vector2f(2., 2.);
static inline const sf::Vector2f VF33 = sf::Vector2f(3., 2.);

#endif
