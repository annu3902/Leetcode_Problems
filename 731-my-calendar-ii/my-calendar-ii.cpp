class Event {
public:
    int start;
    int end;
    
    Event(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class MyCalendarTwo {
    vector<Event> overLapBookings;
    vector<Event> bookings;

public:
    MyCalendarTwo() {
        overLapBookings = vector<Event>();
        bookings = vector<Event>();
    }
    
    bool book(int start, int end) {
        // Check if the new booking overlaps with any double-booked event
        for (const auto& e : overLapBookings) {
            if (isOverlap(e, start, end)) {
                return false;
            }
        }

        // Check for overlap with already booked events and record the overlaps
        for (const auto& e : bookings) {
            if (isOverlap(e, start, end)) {
                overLapBookings.push_back(getOverlapEvent(e, start, end));
            }
        }

        // Add the new event to bookings
        bookings.push_back(Event(start, end));
        return true;
    }

private:
    bool isOverlap(const Event& e, int start, int end) {
        return max(e.start, start) < min(e.end, end);
    }

    Event getOverlapEvent(const Event& e, int start, int end) {
        return Event(max(e.start, start), min(e.end, end));
    }
};