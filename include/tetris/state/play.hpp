#include "state.hpp"

#include "SFML/Graphics/RenderTarget.hpp"

#include "tetris/entity/matrix.hpp"
#include "tetris/entity/geometile.hpp"

class Play 
{
private:
    Matrix matrix;
    std::unique_ptr<Geometile::Geometile> controlled;
    std::unique_ptr<Geometile::Geometile> ghost;

public:
    Play();
    ~Play();

    void render(const std::shared_ptr<sf::RenderTarget>& window);
};
