# Calendar

## 1. What/Why

- Calendar application.
- Events, notifications, reminders.

---

## 2. Requirements and Goals of the System

**Requirements:**

- Add events.
- Reminders.
- Timezones.
- Invite users to events.

---

## 3. High-Level Design

- Calendar.
- Users.
- Events.
- Notification.
- NotificationChannel (email, SMS, etc).

```
User

id: {primaryKey, serial, UUID}
name: string
email: string

            |
            |
            |

UserCalendar

userId: reference userId
calendarId: reference calendarId

            |
            |
            |

Calendar

id: {primaryKey, serial, UUID}
name: string
description: string
timezone: Timezone

            |
            |
            |

CalendarEvent

calendarId: reference calendarId
eventId: reference eventId
role: string

            |
            |
            |

Events

id: {primaryKey, serial, UUID}
name: string
description: stirng
start: DateTime
end: DateTime
allDay: bool

            |
            |
            |

EventNotification

eventId: reference eventId
notificationId: reference notificationId

            |
            |
            |

Notification

id: {primaryKey, serial, UUID}
effective: DateTime
userId: reference userId

            |
            |
            |

NotificationChannel

id: {primaryKey, serial, UUID}
method: string
value: string
userId: reference userId
```

## 4. Low-Level Design

- How would design change if wanted to add the ability to have a team calendar?
- Would need extra info between user and calendar.

```
Team

id: {primaryKey, serial, UUID}
...

            |
            |
            |

TeamUser

teamId: reference teamId
userId: reference userId
roleId: reference roleId
...

            |
            |
            |

Role

id: {primaryKey, serial, UUID}
name: string

            |
            |
            |

Permission

id: {primaryKey, serial, UUID}
action: string

            |
            |
            |
```

- How would this design scale?
- Consider which table would grow the largest.
- For example, events table would be much larger than calendar table, since calendars have tons of events.
- Consider hard to access tables, ex. NotificationChannel.
- Pretty good scale, ex. Notification table has a reference to the NotificationChannel, which would make it able to access data faster.
