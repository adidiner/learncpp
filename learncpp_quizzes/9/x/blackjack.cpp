#include <algorithm>
#include <array>
#include <ctime>
#include <iostream>
#include <random>

enum class Rank {
    r2,
    r3,
    r4,
    r5,
    r6,
    r7,
    r8,
    r9,
    r10,
    jack,
    queen,
    king,
    ace,

    max_ranks
};

enum class Suit {
    clubs,
    diamonds,
    hearts,
    spades,

    max_suits
};

struct Card {
    Rank rank{};
    Suit suit{};
};

constexpr std::size_t deck_size{52};
using deck_t = std::array<Card, deck_size>;
using index_t = deck_t::size_type;

void print_card(const Card& card) {
    char rank{};
    char suit{};

    if (card.rank >= Rank::r2 && card.rank < Rank::r10) {
        rank = static_cast<char>(card.rank) + '2';
    } else {
        switch (card.rank) {
            case Rank::r10:         rank = 'T'; break;
            case Rank::jack:        rank = 'J'; break;
            case Rank::queen:       rank = 'Q'; break;
            case Rank::king:        rank = 'K'; break;
            case Rank::ace:         rank = 'A'; break;
            default:                rank = '?'; break;
        }
    }

    switch (card.suit) {
        case Suit::clubs:       suit = 'C'; break;
        case Suit::diamonds:    suit = 'D'; break;
        case Suit::hearts:      suit = 'H'; break;
        case Suit::spades:      suit = 'S'; break;
        default:                suit = '?'; break;
    }

    std::cout << rank << suit;
}

int get_card_value(const Card& card) {
    if (card.rank == Rank::ace) {
        return 11;
    } else if (card.rank >= Rank::r10 && card.rank <= Rank::king) {
        return 10;
    } else {
        return static_cast<int>(card.rank) + 2;
    }
}

deck_t create_deck() {
    deck_t deck{};
    int suits{static_cast<int>(Suit::max_suits)};
    int ranks{static_cast<int>(Rank::max_ranks)};

    index_t c{};
    for (int s{}; s < suits; ++s) {
        for (int r{}; r < ranks; ++r) {
            deck[c].rank = static_cast<Rank>(r);
            deck[c].suit = static_cast<Suit>(s);
            ++c;
        }
    }
    return deck;
}

void print_deck(const deck_t& deck) {
    for (const auto& card : deck) {
        print_card(card);
        std::cout << ' ';
    }
    std::cout << '\n';
}

void shuffle_deck(deck_t& deck) {
    static std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};
    std::shuffle(deck.begin(), deck.end(), mt);
}

int main() {
    deck_t deck{create_deck()};
    print_deck(deck);
    shuffle_deck(deck);
    print_deck(deck);
    return 0;
}
