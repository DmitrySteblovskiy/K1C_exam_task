#include <iostream>    // стандартные библиотеки
#include <string>
#include <vector>
#include <utility>

#include <lodepng.h>    // добавляем библиотеки для чтения .png файлов и работы с ними

unsigned WIDTH, HEIGHT, ITEM_WIDTH;

std::vector<unsigned char> ConvertImage(const char* filename) {
    // наш формат - можно легко расширить круг покрываемых задач (обрабатывая картинки любого типа):
    std::vector<unsigned char> png;
    std::vector<unsigned char> image; //the raw pixels

    // load and decode
    unsigned error = lodepng::load_file(png, filename);
    if(!error) error = lodepng::decode(image, WIDTH, HEIGHT, png);

    // if there's an error, display it
    if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

    // the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...
    return image;
}

class FieldBorders {    // объект класса содержит границы (пара верхних точек поля - левую и правую), которых нам
public:                 // достаточно для определения основных характеристик поля (высоты клетки и т. д.)
    int x, y;

    FieldBorders( int def_left = 0, int def_right = 0) {
        x = def_left;
        y = def_right;
    }
};

// находим верхние две точки нашего поля (это концы вертикальных линий)
std::pair<FieldBorders, FieldBorders> FindFieldBorders(const std::vector<unsigned char>& image,
                                                       std::pair<FieldBorders, FieldBorders> borders) {
    size_t borders_counter = 0;
    ITEM_WIDTH = 0;

    for (size_t i = 0; i < image.size(); ++i) {     // ищем толщину объектов

        if (image[i] != 255) {
            ++ITEM_WIDTH;
        } else {
            if (ITEM_WIDTH) {
                break;
            }
        }
    }

    for (size_t i = 0; i < image.size(); ++i) {
        if (image[i] != 255 && !borders_counter) {
            borders.first.x = i % WIDTH;
            borders.first.y = i / WIDTH;
            ++borders_counter;
        }

        if (image[i] != 255 && borders_counter == 1) {
            borders.second.x = i % WIDTH;
            borders.second.y = i / WIDTH;
            ++borders_counter;
        }

        if (borders_counter == 2) {
            return borders;
        }
    }
}

std::vector<int> AnalyzeField(std::vector<unsigned char>& image, std::pair<FieldBorders, FieldBorders> borders) {
    std::vector<int> figures(9, 0);
    size_t cell_size = borders.first.x - borders.second.x;

    FieldBorders iteration_beginning;
    iteration_beginning.x = borders.first.x - cell_size;
    iteration_beginning.y = borders.first.y + cell_size / 2;

    for (size_t i = 0; i < 3; ++i) {
        size_t curr_figure = 0;

        for (size_t j = 0; j < iteration_beginning.x + cell_size * 3; ++j) {
            size_t black_counter = 0;

            if ((image[iteration_beginning.y * WIDTH + iteration_beginning.x + j] != 255) &&
                    ((iteration_beginning.y * WIDTH + iteration_beginning.x + j) != (borders.first.x)) &&
                    ((iteration_beginning.y * WIDTH + iteration_beginning.x + j) != (borders.second.x))) {
                ++black_counter;
                j += ITEM_WIDTH + 1;

                if (image[iteration_beginning.y * WIDTH + iteration_beginning.x + j] != 255) {
                    ++black_counter;
                    figures[curr_figure + i * 3] = static_cast<int>(black_counter);
                    ++curr_figure;
                    j = cell_size * curr_figure;
                } else {
                    figures[curr_figure + i * 3] = static_cast<int>(black_counter);
                    ++curr_figure;
                    j = cell_size * curr_figure;
                }
            } else if (image[iteration_beginning.y * WIDTH + iteration_beginning.x + j] != 255) {
                figures[curr_figure + i * 3] = 0;
                ++curr_figure;
                j += ITEM_WIDTH;
            }
        }
        iteration_beginning.y += static_cast<int>(cell_size);
    }

    return figures;
}

void Encode(const char* filename, std::vector<unsigned char>& image, unsigned WIDTH, unsigned HEIGHT) { // проебразование в картинку
    //Encode the image
    unsigned error = lodepng::encode(filename, image, WIDTH, HEIGHT);

    //if there's an error, display it
    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}


void DrawLine(const std::string& orientation, std::vector<int>& winning_line, size_t code) { // рисуем победную линию
}


void MakeAnswer (bool line_exists, std::string& orientation, std::vector<int>& winning_line) {
    if (!line_exists) {   // победителя в игре пока нет
        std::cout << "There is no winner at the moment.";
    } else {
        if (orientation == "horizontal") {      // горизонт победная линия
            // не успел дописать: код в трех ифах аналогичен: мы красим пару соответствующих линий в черный цвет,
            // чтобы показать, какая из них победная. Далее используя библиотечную функцию Encode получаем картинку
        } else if (orientation == "vertical") {     // вертикальная

        } else {    // диагональная

        }
    }
}

void DefineWinnersLine(const std::vector<int>& figures) {
    std::vector<int> winning_line(3, 0);

    for (size_t i = 0; i < 7;) {
        if (figures[i] == figures[i + 3] == figures [i + 6] != 0) {
            winning_line[0] = i;
            winning_line[1] = i + 3;
            winning_line[2] = i + 6;
            MakeAnswer(true, "horizontal", winning_line);
        } else {
            i += 3;
        }
    }

    for (size_t i = 0; i < 3; ++i) {
        if (figures[i] == figures[i + 1] == figures[i + 2] != 0) {
            winning_line[0] = i;
            winning_line[1] = i + 1;
            winning_line[2] = i + 2;
            MakeAnswer(true, "vertical", winning_line);
        }
    }

    for (size_t i = 2; i < 5;) {
        if (figures[4] == figures[4 - i] == figures [4 + i] != 0) {
            winning_line[0] = 4;
            winning_line[1] = 4 - i;
            winning_line[2] = 4 + i;
            MakeAnswer(true, "diagonal", winning_line);
        } else {
            i += 2;
        }
    }

    MakeAnswer(false, "bruh", winning_line);
}


int main() {
    FieldBorders border1, border2;
    std::pair<FieldBorders, FieldBorders> borders = std::make_pair (border1, border2);

    std::vector<unsigned char> image = ConvertImage(filename);   // читаем картинку
    borders = FindFieldBorders(image, borders);   //  ищем границы поля

    std::vector<int> figures = AnalyzeField(image, borders);
    DefineWinnersLine(figures);

    return 0;
}
