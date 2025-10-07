<template>
  <section id="campus" class="py-16">
    <div class="container mx-auto px-4">
      <h2 class="text-3xl font-bold mb-6 text-center underline">Our Campus</h2>
      <div class="flex flex-col md:flex-row items-center gap-8">
        <div class="flex-1">
          <img src="https://via.placeholder.com/600x300" alt="Campus view" class="w-full h-64 rounded-md mb-4 object-cover p-25 border-1">
          <p class="text-lg">Our sprawling 50-acre campus features modern classrooms, labs, and recreational areas.</p>
        </div>
        <div class="flex-1 grid grid-cols-1 gap-4">
          <div
            v-for="(facility, index) in facilities"
            :key="index"
            class=" p-4 rounded-md"
          >
            <h3 class="text-xl font-semibold">{{ facility.name }}</h3>
            <p>{{ facility.description }}</p>
          </div>
        </div>
      </div>
    </div>
  </section>
</template>

<script setup>
import { ref } from 'vue';

const facilities = ref([
  { name: 'State-of-the-Art Labs', description: 'Equipped for hands-on learning in science and tech.' },
  { name: 'Library & Resources', description: 'Over 100,000 books and digital access for research.' },
  { name: 'Sports Facilities', description: 'Gyms, fields, and courts for student wellness.' }
  // Add more facilities
]);
</script>
