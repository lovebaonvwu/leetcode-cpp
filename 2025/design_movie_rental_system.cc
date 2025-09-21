class MovieRentingSystem
{
    unordered_map<int, set<pair<int, int>>> unrented_movies;
    set<tuple<int, int, int>> rented_movies;
    map<pair<int, int>, int> movie_prices;

public:
    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {
        for (const auto &entry : entries)
        {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];

            unrented_movies[movie].insert({price, shop});
            movie_prices[{shop, movie}] = price;
        }
    }

    vector<int> search(int movie)
    {
        vector<int> res;

        if (unrented_movies.count(movie))
        {
            for (const auto &[price, shop] : unrented_movies[movie])
            {
                if (res.size() >= 5)
                {
                    break;
                }
                res.push_back(shop);
            }
        }

        return res;
    }

    void rent(int shop, int movie)
    {
        int price = movie_prices[{shop, movie}];

        unrented_movies[movie].erase({price, shop});

        rented_movies.insert({price, shop, movie});
    }

    void drop(int shop, int movie)
    {
        int price = movie_prices[{shop, movie}];

        rented_movies.erase({price, shop, movie});

        unrented_movies[movie].insert({price, shop});
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> res;

        for (const auto &[price, shop, movie] : rented_movies)
        {
            if (res.size() >= 5)
            {
                break;
            }

            res.push_back({shop, movie});
        }

        return res;
    }
};

// Time: O(e * log(e))
// Space: O(e)