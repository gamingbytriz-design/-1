struct budget_checker {
    virtual void ensure_can_submit(std::int64_t amount) = 0;
    virtual void register_submission(std::int64_t amount) = 0;
    virtual ~budget_checker() = default;
};

class department_budget {
    std::int64_t limit_kopecks_;
    std::int64_t spent_kopecks_;

public:
    department_budget(std::int64_t limit)
        : limit_kopecks_(limit), spent_kopecks_(0) {
        if (limit <= 0) {
            throw invalid_budget_limit(limit);
        }
    }

    void ensure_can_submit(std::int64_t amount) const {
        if (amount > remaining()) {
            throw monthly_budget_exceeded(amount, remaining());
        }
    }

    void register_submission(std::int64_t amount) {
        ensure_can_submit(amount);
        spent_kopecks_ += amount;
    }

    std::int64_t remaining() const {
        return limit_kopecks_ - spent_kopecks_;
    }
};

class department_budget_adapter : public budget_checker {
    department_budget& budget_;

public:
    department_budget_adapter(department_budget& budget) : budget_(budget) {}

    void ensure_can_submit(std::int64_t amount) override {
        budget_.ensure_can_submit(amount);
    }

    void register_submission(std::int64_t amount) override {
        budget_.register_submission(amount);
    }
};

void purchase_request::submit(budget_checker& budget) {
    require_draft();
    if (lines.empty()) {
        throw empty_request(id.value);
    }

    std::int64_t total = total_amount();
    budget.ensure_can_submit(total);
    budget.register_submission(total);

    status = request_status::submitted;
}

struct invalid_budget_limit : domain_error {
    std::int64_t limit;
    invalid_budget_limit(std::int64_t l)
        : domain_error("Invalid budget limit"), limit(l) {}
};

struct monthly_budget_exceeded : domain_error {
    std::int64_t amount;
    std::int64_t remaining;
    monthly_budget_exceeded(std::int64_t a, std::int64_t r)
        : domain_error("Monthly budget exceeded"), amount(a), remaining(r) {}
};
