import json
from datetime import datetime
import matplotlib.pyplot as plt

with open("eva-data.json", "r", encoding="utf-8") as file:
    eva_data = json.load(file)

records = []
country_totals = {}
yearly_totals = {}
country_selected = input("country: ")

for eva in eva_data:
    date_text = eva.get("date")
    duration_text = eva.get("duration")
    country = eva.get("country")
    
    if not date_text or not duration_text:
        continue

    date = datetime.fromisoformat(date_text)
    hours, minutes = map(int, duration_text.split(":"))
    duration_hours = hours + minutes / 60

    year = date.year
    if country is not None:
        country_totals[country] = country_totals.get(country, 0.0) + duration_hours
    
    yearly_totals[year] = yearly_totals.get(year, 0.0) + duration_hours

    records.append((date, duration_hours))

records.sort(key=lambda record: record[0])

dates = []
cumulative_hours = []
total_hours = 0

for date, duration_hours in records:
    total_hours += duration_hours
    dates.append(date)
    cumulative_hours.append(total_hours)

if country_selected in country_totals:
    total_for_country = country_totals[country_selected]
    print(f"Total EVA duration for {country_selected}: {total_for_country:.0f} hours")

plt.figure()
plt.plot(dates, cumulative_hours)
plt.xlabel("Year")
plt.ylabel("Cumulative EVA duration (hours)")
plt.tight_layout()
plt.savefig("cumulative_duration.png")
plt.show()

years = sorted(yearly_totals.keys())
annual_hours = [yearly_totals[y] for y in years]
plt.figure()
plt.plot(years, annual_hours, marker="o")
plt.xlabel("Year")
plt.ylabel("Annual EVA duration (hours)")
plt.title("Annual EVA activity over time")
plt.tight_layout()
plt.savefig("annual_duration.png")
plt.show()

