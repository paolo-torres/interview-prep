# Uber Bike

## How many calls do we anticipate?

- Google handles around 60,000 requests per second, so let's assume 0.5% of that in peak hours.
- Calls here are limited by the number of inventory, aka bicycles, we have.

---

## APIs

`acquireBike()`

`releaseBike()`

---

## SLA

- Not more than 500 ms or so because the user should be able to scan their phone or slide the credit card, and bike should unlock almost immediately.

---

## Critical Components

- Payment most critical component.

---

## Storage Layer

```
Bike Table: to manage available bikes.
User Table: to store user info and metadata.
Trips Table: to save all past trips.
```

- Save all in-progress trips in a Redis cache.
- Keep some data on users' phones themselves.
- Security concern?
- If just saving current trip user's info then it shouldn't be a concern.
- And when trip ends, we can invalidate the cache and move the info to persistent storage.
