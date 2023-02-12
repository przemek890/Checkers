#ifndef PROJEKT_IO_AI_WAGI_H
#define PROJEKT_IO_AI_WAGI_H
//--------------------------
/// WAGI [ dobrane eksperymentalnie ]:

/// PIONEK:
#define wg_1 0.25           // Grupowanie się (jeden pionek)
#define wg_2 0.10           // Grupowanie się (dwa pionki)
#define wg_3 0.35           // Pionek ma wolną drogę, by zostać królową
#define wg_4 1.50           // Nagroda za bicie wielokrotne pionkiem
#define wg_6 0.50           // Nagroda za ruch pionkiem do środka planszy
#define wg_7 -0.25          // Ruch na kraniec planszy pionkiem
#define wg_9 -0.50          // Kara za nie bronienie ostatniej linii przez pionka
#define wg_15 0.35          // Nagroda za unikniecie bicia piona

/// KRÓLOWA:
#define wg_5 1.50           // Nagroda za bicie wielokrotne królową
///     wg_5/2              // Nagroda za bicie krolowa (jednokrotne)
#define wg_10 0.20          // Nagroda za ruch królową do środka planszy
#define wg_11 -0.10         // Ruch na kraniec planszy Królową
#define wg_12 0.50          // Nagroda za pulapke na piona
#define wg_16 0.95          // Nagroda za unikniecie bicia krolowej

/// GENARAL:
#define wg_13 -0.90         // Kara za podejście pod bicie
#define wg_14 -1.80         // Kara za podejście pod bicie wielokrotne




#endif //PROJEKT_IO_AI_H
