#include <algorithm>
#include <array>
#include <ctime>
#include <iostream>
#include <limits>
#include <random>

constexpr int BLACKJACK_VALUE = 21;

class Card {
public:
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

        num_ranks
    };

    enum class Suit {
        clubs,
        diamonds,
        hearts,
        spades,

        num_suits
    };

private:
    Rank m_rank;
    Suit m_suit;

public:
    Card(Rank rank=Rank::ace, Suit suit=Suit::spades)
        : m_rank{rank}, m_suit{suit} {}

    /**
     * print card in "RS" (rank suit) format (e.g, jack of spades - JS)
    */
    void print() const {
        char rank{};
        char suit{};

        if (m_rank >= Rank::r2 && m_rank < Rank::r10) {
            rank = static_cast<char>(m_rank) + '2';
        } else {
            switch (m_rank) {
                case Rank::r10:         rank = 'T'; break;
                case Rank::jack:        rank = 'J'; break;
                case Rank::queen:       rank = 'Q'; break;
                case Rank::king:        rank = 'K'; break;
                case Rank::ace:         rank = 'A'; break;
                default:                rank = '?'; break;
            }
        }

        switch (m_suit) {
            case Suit::clubs:       suit = 'C'; break;
            case Suit::diamonds:    suit = 'D'; break;
            case Suit::hearts:      suit = 'H'; break;
            case Suit::spades:      suit = 'S'; break;
            default:                suit = '?'; break;
        }

        std::cout << rank << suit;
    }

    /**
    * get blackjack value of card
    */ 
    int value() const {
        if (m_rank == Rank::ace) {
            return 11;
        } else if (m_rank >= Rank::r10 && m_rank <= Rank::king) {
            return 10;
        } else {
            return static_cast<int>(m_rank) + 2;
        }
    }

};


class Deck {
public:
    static constexpr size_t DECK_SIZE = 52;
    using deck_t = std::array<Card, DECK_SIZE>;

private:
    deck_t m_deck;
    size_t m_top;

public:
    /**
     * create standard deck 
     */
    Deck() : m_deck{}, m_top{0} {
        int suits{static_cast<int>(Card::Suit::num_suits)};
        int ranks{static_cast<int>(Card::Rank::num_ranks)};

        size_t c{};
        for (int s{}; s < suits; ++s) {
            for (int r{}; r < ranks; ++r) {
                m_deck[c] = {static_cast<Card::Rank>(r), static_cast<Card::Suit>(s)};
                ++c;
            }
        }
    }

    void print() const {
        for (const auto& card : m_deck) {
            card.print();
            std::cout << ' ';
        }
        std::cout << '\n';
    }

    void shuffle(int seed=0) {
        m_top = 0; // reset top of sdeck
        auto mt_seed{static_cast<std::mt19937::result_type>(seed)};
        // if seed is 0 (or not provided), use random seed
        if (seed == 0) {
            mt_seed = static_cast<std::mt19937::result_type>(std::time(nullptr));
        }
        static std::mt19937 mt{mt_seed};
        std::shuffle(m_deck.begin(), m_deck.end(), mt);
    }

    const Card& deal_card () {
        return m_deck[m_top++];
    }
};

class Player {
public:
    using hand_t = std::vector<Card>;

private:
    hand_t hand;

public:
    
}
// using hand_t = std::vector<Card>;


// /**
//  * calaculate total blackjack value of hand
//  */
// int total_hand(const hand_t& hand) {
//     int sum{};
//      for (const auto& card : hand) {
//         sum += get_card_value(card);
//     }
//     return sum;
// }

// void print_hand(const hand_t& hand) { 
//     for (const auto& card : hand) {
//         print_card(card);
//         std::cout << ' ';
//     }
//     std::cout << "\nTotal: " << total_hand(hand) << '\n';
// }

 
// /**
//  * clear std::cin buffer
//  */
// void ignore_line() {
//   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
// }

// /**
//  * prompt player for action (hit or stand), return 'h' or 's'
//  */
// char get_player_action() {
//     char action{};
//     do {
//         std::cout << "\nHit or stand? (h/s) ";
//         std::cin >> action;
//         if (action == 'h' || action == 's') {
//             return action;
//         }
//         ignore_line();
//         std::cout << "Invalid input\n";
//     } while (true);
// }

// /**
//  * perform player turn
//  * 
//  * @param deck game deck
//  * @param hand initial player hand
//  * @param top current deck top
//  * @return true if player didnt bust
//  */
// bool player_turn(const deck_t& deck, hand_t& hand, size_t& top) {
//     while (true) {
//         char action{get_player_action()};  
//         if (action == 's') {
//             return true;
//         }
//         hand.push_back(draw(deck, top));
//         print_hand(hand);
//         if (total_hand(hand) > blackjack) {
//             return false;
//         }
//     }
// }

// /**
//  * perform dealer turn
//  * 
//  * @param deck game deck
//  * @param hand initial dealer hand
//  * @param top current deck top
//  * @return true if dealer didnt bust
//  */
// bool dealer_turn(const deck_t& deck, hand_t& hand, size_t& top) {
//     constexpr int done{17};
//     while (true) {
//         hand.push_back(draw(deck, top));
//         if (int total{total_hand(hand)}; total > done) {
//             print_hand(hand);
//             if (total > blackjack) {
//                 return false;
//             }
//             return true;
//         }
//     }
// }

// /**
//  * simplfied game of blackjack
//  * 
//  * @param deck mixed standard card deck
//  * @return true if player won, false otherwise
//  */
// bool play_blackjack(const deck_t& deck) {
//     size_t top{}; // current top of the deck
//     hand_t dealer{draw(deck, top)};
//     hand_t player{draw(deck, top), draw(deck, top)};

//     std::cout << "Player hand\n";
//     print_hand(player);
//     std::cout << "\nDealer hand\n";
//     print_hand(dealer);

//     std::cout << "\nPlayer's turn:\n";
//     if (!player_turn(deck, player, top)) {
//         std::cout << "Bust!\n";
//         return false;
//     }
//     std::cout << "\nDealer's turn:\n\n";
//     if (!dealer_turn(deck, dealer, top)) {
//         std::cout << "Dealer bust!\n";
//         return true;
//     }
//     return (total_hand(player) > total_hand(dealer));
// }

int main() {
//     deck_t deck{create_deck()};
//     shuffle_deck(deck);
//     if (play_blackjack(deck)) {
//         std::cout << "You win!\n";
//     } else {
//         std::cout << "You lose!\n";
//     }
    Deck deck{};
    deck.print();
    deck.shuffle();
    deck.print();
    std::cout << "The first card has value: " << deck.deal_card().value() << '\n';
    std::cout << "The second card has value: " << deck.deal_card().value() << '\n';
    return 0;
}
