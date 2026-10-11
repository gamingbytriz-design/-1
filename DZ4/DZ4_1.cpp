void remove_line(LineId id);

void PurchaseRequest::remove_line(LineId id) {
    require_draft();

    auto it = std::find_if(lines.begin(), lines.end(),
        [id](const RequestLine& line) {
            return line.get_id().value == id.value;
        });

    if (it == lines.end()) {
        throw LineNotFound(id.value);
    }

    lines.erase(it);
}

struct LineNotFound : DomainError {
    std::int64_t line_id;
    LineNotFound(std::int64_t id)
        : DomainError("Line not found"), line_id(id) {}
};
