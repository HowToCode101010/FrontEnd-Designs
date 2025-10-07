<template>
    <section id="courses" class="py-16">
        <div class="container mx-auto px-4">
            <h2 class="text-3xl font-bold mb-6 text-center underline">Our Courses</h2>
            <div class="grid grid-cols-1 md:grid-cols-3 gap-6">
            <div v-for = "(course, index) in courses" :key="index" class="p-6 rounded-md shadow-md">
                <h3 class="text-xl font-semibold mb-2 underline">{{ course.name }}</h3>
                <p>{{ course.description }}</p>
            </div>
            </div>
        </div>

    </section>
</template>
<script setup>
import {ref} from 'vue';
const courses = ref([
    {name : 'Computer Science', description: 'Learn Programming, AI, and more.'},
    {name: 'Business Management', description: 'Master leadership & strategy.'},
    {name: 'Graphic Design', description: 'Creative skills for the digital age.'}
]);
</script>
