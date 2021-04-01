#include <algorithm>
#include <array>
#include <ctime>
#include <iostream>
#include <limits>
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

constexpr size_t deck_size{52};
constexpr int blackjack{21};

using deck_t = std::array<Card, deck_size>;
using hand_t = std::vector<Card>;

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

    size_t c{};
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

int total_hand(const hand_t& hand) {
    int sum{};
     for (const auto& card : hand) {
        sum += get_card_value(card);
    }
    return sum;
}

void print_hand(const hand_t& hand) { 
    for (const auto& card : hand) {
        print_card(card);
        std::cout << ' ';
    }
    std::cout << "\nTotal: " << total_hand(hand) << '\n';
}

const Card& draw(const deck_t& deck, size_t& top) {
    return deck[top++];
}
 
void ignore_line() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

char get_player_action() {
    char action{};
    do {
        std::cout << "\nHit or stand? (h/s) ";
        std::cin >> action;
        if (action == 'h' || action == 's') {
            return action;
        }
        ignore_line();
        std::cout << "Invalid input\n";
    } while (true);
}

bool player_turn(const deck_t& deck, hand_t& hand, size_t& top) {
    while (true) {
        char action{get_player_action()};  
        if (action == 's') {
            return true;
        }
        hand.push_back(draw(deck, top));
        print_hand(hand);
        if (total_hand(hand) > blackjack) {
            return false;
        }
    }
}

bool dealer_turn(const deck_t& deck, hand_t& hand, size_t& top) {
    constexpr int done{17};
    while (true) {
        hand.push_back(draw(deck, top));
        if (int total{total_hand(hand)}; total > done) {
            print_hand(hand);
            if (total > blackjack) {
                return false;
            }
            return true;
        }
    }
}

bool play_blackjack(const deck_t& deck) {
    size_t top{}; // current top of the deck
    hand_t dealer{draw(deck, top)};
    hand_t player{draw(deck, top), draw(deck, top)};

    std::cout << "Player hand\n";
    print_hand(player);
    std::cout << "\nDealer hand\n";
    print_hand(dealer);

    std::cout << "\nPlayer's turn:\n";
    if (!player_turn(deck, player, top)) { // player busted
        std::cout << "Bust!\n";
        return false;
    }
    std::cout << "\nDealer's turn:\n\n";
    if (!dealer_turn(deck, dealer, top)) { // dealer busted
        std::cout << "Dealer bust!\n";
        return true;
    }
    return (total_hand(player) > total_hand(dealer));
}

int main() {
    deck_t deck{create_deck()};
    shuffle_deck(deck);
    if (play_blackjack(deck)) {
        std::cout << "You win!\n";
    } else {
        std::cout << "You lose!\n";
    }

    return 0;
}
